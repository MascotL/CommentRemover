#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    // 打开文件
    FILE *originalFile, *tempFile;
    char originalFileName[] = "[Comment].txt";
    char tempFileName[] = "[AfterComment].txt";
    
    // 以只读方式打开原文件，以写入方式打开临时文件
    originalFile = fopen(originalFileName, "r");
    tempFile = fopen(tempFileName, "w");
    
    // 检查文件是否打开成功
    if  (originalFile == NULL || tempFile == NULL) {
        printf("cannot open\n");
        return 1;
    }
    
    char line[256] = ""; // 用于存储读取的行
    bool isComment = false;
    
    // 读取一行到line[]，直到文件结尾
    while (fgets(line, sizeof(line), originalFile) != NULL) {
        char *ss = strstr(line, "//");
        char *sa = strstr(line, "/*");
        char *as = strstr(line, "*/");
        
        if (isComment){
            if (as == NULL) {       // "*/"不存在
                memset(line, 0, sizeof(line));
                continue;
            } else {        // "*/"存在
                for (int i = 0; ; i++) {
                    line[i] = ' ';
                    if (&line[i]-1 == as) {
                        fputs(line, tempFile);
                        isComment = false;
                        break;
                    }
                }
            }
        } else if (ss == NULL && sa == NULL) { // 无注释
            fputs(line, tempFile);
        } else if (ss != NULL && sa == NULL) { // "//"存在
            *ss = '\n';
            *(ss + 1) = '\0';
            fputs(line, tempFile);
        } else if (ss == NULL && sa != NULL) { // "/*"存在
            if (as != NULL) {       // "*/"也存在
                for (int i = 0; ; i++) {
                    *(sa + i) = ' ';
                    if ((sa+i-1) == as) {
                        fputs(line, tempFile);
                        break;
                    }
                }
            } else {        // "*/"不存在
                isComment = true;
                *sa = '\n';
                *(sa + 1) = '\0';
                fputs(line, tempFile);
            }
        } else if (ss != NULL && sa != NULL) { // "//"和"/*"都存在
            if (ss < sa) {
                *ss = '\n';
                *(ss + 1) = '\0';
                fputs(line, tempFile);
            } else {
                isComment = true;
                *sa = '\n';
                *(sa + 1) = '\0';
                fputs(line, tempFile);
            }
        }
        memset(line, 0, sizeof(line)); // 清空line[]
    }
    
    // 关闭文件
    fclose(originalFile);
    fclose(tempFile);

    printf("\ndone\n");
    
    // // 删除原文件，将临时文件重命名为原文件
    // remove(originalFileName);
    // rename(tempFileName, originalFileName);
    
    return 0;
}
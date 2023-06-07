#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <stdbool.h>


void fileTypeFilter();
void deleteAllFile();
void delete(char *fileAddress);
void delete_c(char *fileAddress);
void delete_py(char *fileAddress);
void delete_php(char *fileAddress);
void delete_rb(char *fileAddress);
void delete_html(char *fileAddress);
void delete_css(char *fileAddress);

int main() {
    system("chcp 65001 > nul"); // 设置编码为UTF-8
    printf("这些文件将被执行:\n");

    fileTypeFilter();

    printf("\n输入 \"delete\" 执行\n");
    printf("或者手动输入文件地址\n");

    while(1){
        printf("\n> ");

        char input[255] = "";
        scanf("%s", &input);

        if (strcmp(input, "delete") == 0) { // 判断是否为delete
            printf("按 'y' 继续...\n\n");
            char *confirm;

            if(_getch() == 'y' || _getch() == 'Y') {
                deleteAllFile();
            }
        } else if (input[1] == ':' && input[2] == '\\') { // 判断是否为文件路径
            delete(input);
        } else { // 错误输入
            printf("请输入正确的路径\n");
        }
    }

    return 0;
}

void fileTypeFilter() {
    const char *directory = ".";  // 当前文件夹
    DIR *dir;
    struct dirent *entry;

    // 打开目录
    dir = opendir(directory);
    if (dir == NULL) {
        printf("无法打开当前文件夹\n");
        return;
    }

    // 遍历目录中的文件
    while ((entry = readdir(dir)) != NULL) {
    const char *extension = strrchr(entry->d_name, '.');
            if (extension != NULL) {
                if (strcmp(extension, ".c") == 0 ||
                    strcmp(extension, ".cpp") == 0 ||
                    strcmp(extension, ".java") == 0 ||
                    strcmp(extension, ".js") == 0 ||
                    strcmp(extension, ".swift") == 0 ||
                    strcmp(extension, ".rs") == 0 ||
                    strcmp(extension, ".php") == 0 ||
                    strcmp(extension, ".py") == 0 ||
                    strcmp(extension, ".rb") == 0 ||
                    strcmp(extension, ".go") == 0 ||
                    strcmp(extension, ".html") == 0 ||
                    strcmp(extension, ".css") == 0) {
                    printf(" - %s\n", entry->d_name);
                }
            }
        }
    closedir(dir);
}

void deleteAllFile() {
    const char *directory = ".";  // 当前文件夹
    DIR *dir;
    struct dirent *entry;

    // 打开目录
    dir = opendir(directory);
    if (dir == NULL) {
        printf("无法打开当前文件夹\n");
        return;
    }

    // 获取当前文件夹路径
    char buffer[255];
    GetModuleFileName(NULL, buffer, sizeof(buffer));
    char* lastSlash = strrchr(buffer, '\\');
    if (lastSlash != NULL) {
        // 将反斜杠的下一位替换为字符串结束符
        *(lastSlash + 1) = '\0';
    }

    // 遍历目录中的文件
    char fileAddress[255];
    while ((entry = readdir(dir)) != NULL) {
    const char *extension = strrchr(entry->d_name, '.');
        if (extension != NULL) {
            if (strcmp(extension, ".c") == 0 ||
                strcmp(extension, ".cpp") == 0 ||
                strcmp(extension, ".java") == 0 ||
                strcmp(extension, ".js") == 0 ||
                strcmp(extension, ".swift") == 0 ||
                strcmp(extension, ".rs") == 0 ||
                strcmp(extension, ".php") == 0 ||
                strcmp(extension, ".py") == 0 ||
                strcmp(extension, ".rb") == 0 ||
                strcmp(extension, ".go") == 0 ||
                strcmp(extension, ".html") == 0 ||
                strcmp(extension, ".css") == 0) {
                // 将文件路径拼接
                printf("\"%s\" 删除中...\n", entry->d_name); // 打印文件名
                strcpy(fileAddress, buffer); // 拼接文件夹路径
                char *lastZero = strrchr(fileAddress, '\0'); // 获取字符串结束符的位置
                strcpy(lastZero, entry->d_name); // 拼接文件名
                delete(fileAddress); // 删除文件
            }
        }
    }
    printf("结束!\n");
    closedir(dir);
}

void delete(char *fileAddress) {
    if(access(fileAddress, F_OK) != 0) {
        printf("\"%s\" 路径不存在", fileAddress);
        return;
    }
    // 判断文件名后缀
    const char *extension = strrchr(fileAddress, '.');
    if (extension == NULL) {
        printf("\"%s\" 未知文件", fileAddress);
        return;
    } else if (strcmp(extension, ".c") == 0 ||
            strcmp(extension, ".cpp") == 0 ||
            strcmp(extension, ".java") == 0 ||
            strcmp(extension, ".js") == 0 ||
            strcmp(extension, ".swift") == 0 ||
            strcmp(extension, ".rs") == 0 ||
            strcmp(extension, ".go") == 0) {
        delete_c(fileAddress);
    } else if (strcmp(extension, ".py") == 0) {
        delete_py(fileAddress);
    } else if (strcmp(extension, ".php") == 0) {
        delete_php(fileAddress);
    } else if (strcmp(extension, ".rb") == 0) {
        delete_rb(fileAddress);
    } else if (strcmp(extension, ".html") == 0) {
        delete_html(fileAddress);
    } else if (strcmp(extension, ".css") == 0) {
        delete_css(fileAddress);
    } else {
        printf("\"%s\" 非法文件", fileAddress);
        return;
    }
}

void delete_c(char *fileAddress){
    // 打开文件
    FILE *originalFile, *tempFile;
    char originalFileName[] = "";
    strcpy(originalFileName, fileAddress);
    char tempFileName[] = "temp.txt";
    
    // 以只读方式打开原文件，以写入方式打开临时文件
    originalFile = fopen(originalFileName, "r");
    tempFile = fopen(tempFileName, "w");
    
    // 检查文件是否打开成功
    if  (originalFile == NULL || tempFile == NULL) {
        printf("打开失败\n");
        return ;
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

    // 删除原文件，将临时文件重命名为原文件
    remove(originalFileName);
    rename(tempFileName, originalFileName);

    printf("执行完成\n\n");
}

void delete_py(char *fileAddress){
    printf("开发中...\n");
}

void delete_php(char *fileAddress){
    printf("开发中...\n");
}

void delete_rb(char *fileAddress){
    printf("开发中...\n");
}

void delete_html(char *fileAddress){
    printf("开发中...\n");
}

void delete_css(char *fileAddress){
    printf("开发中...\n");
}
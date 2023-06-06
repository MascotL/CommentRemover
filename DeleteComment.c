#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>


void fileTypeFilter();
void deleteAllFile();
void delete(char *fileAddress);

int main() {
    printf("These files will be executed:\n");

    fileTypeFilter();

    printf("\nEnter \"delete\" to execute\n");
    printf("Or drag the file in.\n");

    while(1){
        printf("\n> ");

        char input[255] = "";
        scanf("%s", &input);

        if (strcmp(input, "delete") == 0) { // 判断是否为delete
            printf("Type 'y' to continue...\n\n");
            char *confirm;

            if(_getch() == 'y' || _getch() == 'Y') {
                deleteAllFile();
            }
        } else if (input[1] == ':' && input[2] == '\\') { // 判断是否为文件路径
            delete(input);
        } else { // 错误输入
            printf("Invalid input.\n");
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
        printf("Cannot open directory.\n");
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
        printf("Cannot open directory.\n");
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
                printf("\"%s\" Deletion...\n", entry->d_name);
                strcpy(fileAddress, buffer);
                char *lastZero = strrchr(fileAddress, '\0');
                strcpy(lastZero, entry->d_name);
                delete(fileAddress);
            }
        }
    }
    printf("Done!\n");
    closedir(dir);
}

void delete(char *fileAddress) {
    if(access(fileAddress, F_OK) != 0) {
        printf("\"%s\" does not exist!", fileAddress);
        return;
    }
    
}


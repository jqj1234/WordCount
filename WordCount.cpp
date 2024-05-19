#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// 函数声明
int countCharacters(FILE* file);
int countWords(FILE* file);

int main(int argc, char* argv[]) {
    // 检查参数个数
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    // 打开文件
    FILE* file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("文件打开失败 %s\n", argv[2]);
        return 1;
    }

    int count;
    // 根据参数调用相应的函数
    if (strcmp(argv[1], "-c") == 0) {
        count = countCharacters(file);
        printf("字符数: %d\n", count);
    }
    else if (strcmp(argv[1], "-w") == 0) {
        count = countWords(file);
        printf("单词数: %d\n", count);
    }
    else {
        printf("无效参数\n");
        return 1;
    }

    fclose(file);
    return 0;
}

// 统计字符数
int countCharacters(FILE* file) {
    int charCount = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        charCount++;
    }
    return charCount;
}

// 统计单词数
int countWords(FILE* file) {
    int wordCount = 0;
    char ch;
    int inWord = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == ',' || ch == '\t' || ch == '\n') {
            if (inWord) {
                inWord = 0;
                wordCount++;
            }
        }
        else {
            inWord = 1;
        }
    }
    // 处理文件结尾的情况
    if (inWord) {
        wordCount++;
    }
    return wordCount;
}

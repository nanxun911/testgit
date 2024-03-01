//
// Created by 倪 on 2024/2/26.
//
#include "account.h"
int EntryCheck(char* id, char* password) { //登录校验的函数
    char adminerId[IDLENGTH] = {"100000"};
    char adminerPassword[PASSWORDLENGTH] = {"11111"};
    if (strcmp(id,adminerId) == 0 && strcmp(password, adminerPassword) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}
int Login(char* studentId, char* studentPassword){
    char ch;
    int i = 0;
    int limit = 3;
    printf("请输入你的账号：");
    fgets(studentId, IDLENGTH, stdin);
    studentId[strlen(studentId) - 1] = '\0';
    printf("请输入你的密码：");
    while ((ch = getch()) != '\r' && i < PASSWORDLENGTH) {
        if (ch == '\b' && i > 0) {
            printf("\b \b");
            i--;
        } else if (ch != '\b') {
            printf("*");
            studentPassword[i] = ch;
            i++;
        }
    }
    studentPassword[i] = '\0';
    while (strcmp(studentPassword, "\0") == 0) {
        printf("\n");
        i = 0;
        limit--;
        if (limit == 0) {
            printf("次数结束等待五分钟后重新登录\n");
            break;
        }
        printf("还有%d次机会\n", limit);
        printf("你未输入密码\n请输入密码：");
        while ((ch = getch()) != '\r' && i < PASSWORDLENGTH) {
            if (ch == '\b' && i > 0) {
                printf("\b \b");
                i--;
            } else if (ch != '\b') {
                printf("*");
                studentPassword[i] = ch;
                i++;
            }
        }
        studentPassword[i] = '\0';
    }
    return EntryCheck(studentId,studentPassword);
}
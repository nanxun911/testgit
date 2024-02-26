//
// Created by 倪 on 2024/2/26.
//
#include "account.h"
int EntryCheck(char* id, char* password) { //登录校验的函数
    char adminerId[IDLENGTH] = {"100000"};
    char adminerPassword[PASSWORDLENGTH] = {"11111"};
    FILE* fp = fopen("E:\\dromAccount.txt","rb");
    int tmp = 0;
    if (fp == NULL) {
        perror("file error");
        exit(-1);
    }
    if (strcmp(id,adminerId) == 0 && strcmp(password, adminerPassword) == 0) {
        return 1;
    }
    else {
        account user;
        while (!feof(fp)) {
            tmp = fread(&user, sizeof(account), 1, fp);
            if (tmp > 0 && strcmp(id,user.username) == 0 && strcmp(password, user.password) == 0 ){
                fclose(fp);
                return 2;
            }
        }
        fclose(fp);
    }
    return 3;
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
void interface()//主界面
{
    printf("\n\n");
    printf("\t---------------------------------------------------------\n");
    printf("\t|\t\t欢迎使用宿舍信息管理系统\t\t|\n");
    printf("\t---------------------------------------------------------\n");
    printf("\t|\t\t\t1-录入数据\t\t\t|\n");
    printf("\t|\t\t\t2-数据增加\t\t\t|\n");
    printf("\t|\t\t\t3-数据删除\t\t\t|\n");
    printf("\t|\t\t\t4-数据修改\t\t\t|\n");
    printf("\t|\t\t\t5-数据查询\t\t\t|\n");
    printf("\t|\t\t\t6-数据统计\t\t\t|\n");
    printf("\t|\t\t\t7-数据报表\t\t\t|\n");
    printf("\t---------------------------------------------------------\n");
}
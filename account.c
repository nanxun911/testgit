//
// Created by �� on 2024/2/26.
//
#include "account.h"
int EntryCheck(char* id, char* password) { //��¼У��ĺ���
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
    printf("����������˺ţ�");
    fgets(studentId, IDLENGTH, stdin);
    studentId[strlen(studentId) - 1] = '\0';
    printf("������������룺");
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
            printf("���������ȴ�����Ӻ����µ�¼\n");
            break;
        }
        printf("����%d�λ���\n", limit);
        printf("��δ��������\n���������룺");
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
//
// Created by �� on 2024/2/26.
//
#include "account.h"
int EntryCheck(char* id, char* password) { //��¼У��ĺ���
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
void interface()//������
{
    printf("\n\n");
    printf("\t---------------------------------------------------------\n");
    printf("\t|\t\t��ӭʹ��������Ϣ����ϵͳ\t\t|\n");
    printf("\t---------------------------------------------------------\n");
    printf("\t|\t\t\t1-¼������\t\t\t|\n");
    printf("\t|\t\t\t2-��������\t\t\t|\n");
    printf("\t|\t\t\t3-����ɾ��\t\t\t|\n");
    printf("\t|\t\t\t4-�����޸�\t\t\t|\n");
    printf("\t|\t\t\t5-���ݲ�ѯ\t\t\t|\n");
    printf("\t|\t\t\t6-����ͳ��\t\t\t|\n");
    printf("\t|\t\t\t7-���ݱ���\t\t\t|\n");
    printf("\t---------------------------------------------------------\n");
}
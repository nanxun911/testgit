#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "LinkList.h"
#include "account.h"
int main() {
    char studentId[23];
    char password[20];
    int status = 3;
    while(status) {
    switch (Login(studentId, password)) {
        case 1:
            system("cls");
            SelectMenu();
        default:
            printf("登陆失败\n");
            status--;
            printf("还有%d次机会\n", status);
    }
}
    system("Pause");
    return 0;
}







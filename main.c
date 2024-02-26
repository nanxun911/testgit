#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "LinkList.h"
#include "account.h"
int main() {
    LinkList * head;

    head = ReadLinkList();
    Print(head);
    system("Pause");
    return 0;
}







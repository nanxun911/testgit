//
// Created by ƒﬂ on 2024/2/26.
//

#ifndef DROM_LINKLIST_H
#define DROM_LINKLIST_H
#include "account.h"
typedef struct student{  //Àﬁ…·–≈œ¢
    char dorm[50];
    int dormNum;
    int dormNumId;
    char id[10];
    char name[10];
    char major[20];
    int age;
    char number[12];
    char sex[3];
}student;
typedef struct LinkList{
    student student1;
    struct LinkList* next;
}LinkList;
LinkList *CreatList();
void Print(LinkList *head);
int FindId(char id[],LinkList *head);
int FindCheck(LinkList *head,LinkList *p);
void WriteLinkList(LinkList *head);
LinkList * ReadLinkList();
#endif //DROM_LINKLIST_H


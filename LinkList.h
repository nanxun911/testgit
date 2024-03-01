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
LinkList * ReadLinkList();
void Print(LinkList *head);
int FindId(char id[],LinkList *head);
int FindCheck(LinkList *head,LinkList *p);
void WriteLinkList(LinkList* head);
void AddNewStudent();
int SearchStudent(char* id);
int SearchStudentName(char* name);
int SearchStudentDrom(char* drom);
int DeleteStudent(char* id);
int ModifyStudent(char* id);
void SortNodeById(LinkList* head);
void initInterface();
void SortNodeByIdDown(LinkList* head);
void SelectMenu();
void interface1();
void SonOperation(LinkList *head);
void StatisticalTotal(LinkList *head);
void StatisticalDorm(LinkList *head);
void StatisticalDormNum(LinkList *head);
void StatisticalOperation(LinkList *head);
void SonStatistical();
#endif //DROM_LINKLIST_H


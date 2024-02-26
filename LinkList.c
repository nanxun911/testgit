//
// Created by 倪 on 2024/2/26.
//
#include "LinkList.h"
LinkList * CreatList()//创建链表
{
    LinkList *head,*end,*p;
    char id[10];
    head=NULL;
    head = (LinkList *)malloc(sizeof(LinkList ));
    head->next=NULL;
    end=head;
    printf("\t输入学号:");
    fflush(stdin);
    gets(id);
    while(strlen(id)>0){
        if(FindId(id,head)){//学号查重,重复返回0，否则1
            p=(LinkList *)malloc(sizeof(LinkList ));
            strcpy(p->student1.id,id);
            printf("\t输入姓名:");
            gets(p->student1.name);
            printf("\t输入公寓名称:");
            scanf("%s",p->student1.dorm);
            printf("\t输入宿舍名称:");
            scanf("%d",&(p->student1.dormNum));
            printf("\t输入床位号:");
            scanf("%d",&(p->student1.dormNumId));
            if(FindCheck(head,p)){ //检查宿舍是否满员,符合返回1，不符合返回0
                printf("\t手机号:");
                fflush(stdin);
                gets(p->student1.number);
                printf("\t年龄:");
                scanf("%d",&(p->student1.age));
                printf("\t性别:");
                scanf("%s",p->student1.sex);
                printf("\t专业班级:");
                scanf("%s",p->student1.major);
                end->next=p;
                end=p;
                p->next=NULL;
            }
        }
        printf("\t输入学号:");
        fflush(stdin);
        gets(id);
    }
    return head;
}
int FindId(char id[],LinkList *head){//学号查重,重复返回0，否则1
    LinkList *i;
    for(i = head->next; i!=NULL; i = i->next){
        if(strcmp(id,i->student1.id)==0){
            printf("\t学号重复\n");
            return 0;
        }
    }
    return 1;
}
void Print(LinkList *head){//链表打印输出
    LinkList *i;
    for(i = head->next; i != NULL; i = i->next){
        printf("\t|%-10s%-8s%-9s%-10s%-5d%-5d%-5s%-5d%-12s|\n",i->student1.id,i->student1.name,i->student1.major,i->student1.dorm,i->student1.dormNum,i->student1.dormNumId,i->student1.sex,i->student1.age,i->student1.number);
    }
}
LinkList * ReadLinkList(){//读取文件
    FILE* fp;
    int tmp = 0;
    fp=fopen("E:\\drom.txt","rb+");
    LinkList* i;
    LinkList * head;
    head=NULL;
    head=(LinkList *)malloc(sizeof(LinkList ));
    LinkList *end,*p;
    end = head;
    while(!feof(fp)){
        p=(LinkList *)malloc(sizeof(LinkList ));
        tmp = fread(&(p->student1),sizeof(student),1,fp);
        if (tmp == 0) {
            break;
        }
        end->next = p;
        end = p;
        p->next = NULL;
    }
    fclose(fp);
    return head;
}
int FindCheck(LinkList *head,LinkList *p) {//检查宿舍是否满员,符合返回1，不符合返回0
    //print(head);   //测试
    //printf("进入\n");
    LinkList *i;
    for(i = head->next; i != NULL; i = i->next){
        if(!strcmp(p->student1.dorm, i->student1.dorm) && (p->student1.dormNumId==i->student1.dormNumId) && (p->student1.dormNum==i->student1.dormNum)){
            printf("\t宿舍信息重复\n");
            return 0;
        }
    }
    return 1;
}
void WriteLinkList(LinkList *head){  //用链表，生成文件
    FILE *fp;
    fp=fopen("E:\\drom.txt","wb");
    LinkList *i;
    for(i = head->next; i != NULL; i = i->next){
        fwrite(&(i->student1), sizeof(student) , 1, fp);
    }
    fclose(fp);
}
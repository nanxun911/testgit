//
// Created by �� on 2024/2/26.
//
#include "LinkList.h"
LinkList * CreatList()//��������
{
    LinkList *head,*end,*p;
    char id[10];
    head=NULL;
    head = (LinkList *)malloc(sizeof(LinkList ));
    head->next=NULL;
    end=head;
    printf("\t����ѧ��:");
    fflush(stdin);
    gets(id);
    while(strlen(id)>0){
        if(FindId(id,head)){//ѧ�Ų���,�ظ�����0������1
            p=(LinkList *)malloc(sizeof(LinkList ));
            strcpy(p->student1.id,id);
            printf("\t��������:");
            gets(p->student1.name);
            printf("\t���빫Ԣ����:");
            scanf("%s",p->student1.dorm);
            printf("\t������������:");
            scanf("%d",&(p->student1.dormNum));
            printf("\t���봲λ��:");
            scanf("%d",&(p->student1.dormNumId));
            if(FindCheck(head,p)){ //��������Ƿ���Ա,���Ϸ���1�������Ϸ���0
                printf("\t�ֻ���:");
                fflush(stdin);
                gets(p->student1.number);
                printf("\t����:");
                scanf("%d",&(p->student1.age));
                printf("\t�Ա�:");
                scanf("%s",p->student1.sex);
                printf("\tרҵ�༶:");
                scanf("%s",p->student1.major);
                end->next=p;
                end=p;
                p->next=NULL;
            }
        }
        printf("\t����ѧ��:");
        fflush(stdin);
        gets(id);
    }
    return head;
}
int FindId(char id[],LinkList *head){//ѧ�Ų���,�ظ�����0������1
    LinkList *i;
    for(i = head->next; i!=NULL; i = i->next){
        if(strcmp(id,i->student1.id)==0){
            printf("\tѧ���ظ�\n");
            return 0;
        }
    }
    return 1;
}
void Print(LinkList *head){//�����ӡ���
    LinkList *i;
    for(i = head->next; i != NULL; i = i->next){
        printf("\t|%-10s%-8s%-9s%-10s%-5d%-5d%-5s%-5d%-12s|\n",i->student1.id,i->student1.name,i->student1.major,i->student1.dorm,i->student1.dormNum,i->student1.dormNumId,i->student1.sex,i->student1.age,i->student1.number);
    }
}
LinkList * ReadLinkList(){//��ȡ�ļ�
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
int FindCheck(LinkList *head,LinkList *p) {//��������Ƿ���Ա,���Ϸ���1�������Ϸ���0
    //print(head);   //����
    //printf("����\n");
    LinkList *i;
    for(i = head->next; i != NULL; i = i->next){
        if(!strcmp(p->student1.dorm, i->student1.dorm) && (p->student1.dormNumId==i->student1.dormNumId) && (p->student1.dormNum==i->student1.dormNum)){
            printf("\t������Ϣ�ظ�\n");
            return 0;
        }
    }
    return 1;
}
void WriteLinkList(LinkList *head){  //�����������ļ�
    FILE *fp;
    fp=fopen("E:\\drom.txt","wb");
    LinkList *i;
    for(i = head->next; i != NULL; i = i->next){
        fwrite(&(i->student1), sizeof(student) , 1, fp);
    }
    fclose(fp);
}
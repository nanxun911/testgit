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
    scanf("%s", id);
    getchar();
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
    int chas = 0;
    for(i = head->next; i != NULL; i = i->next){
        if (chas == 0) {
            printf("| %-10s | %-8s | %-9s | %-10s | %-7s | %-9s | %-5s | %-4s | %-12s |\n",
                   "ID", "Name", "Major", "Dorm", "DormNum", "DormNumId", "Sex", "Age", "Number");
            chas = 1;
            printf("----------------------------------------------------------------------------------\n");
        }
        printf("| %-10s | %-8s | %-9s | %-10s | %-7d | %-9d | %-5s | %-4d | %-12s |\n",
               i->student1.id, i->student1.name, i->student1.major, i->student1.dorm, i->student1.dormNum,
               i->student1.dormNumId, i->student1.sex, i->student1.age, i->student1.number);
    }
}
LinkList * ReadLinkList(){//��ȡ�ļ�
    FILE* fp;
    if (fp == NULL) {
        perror("file error");
        exit(-1);
    }
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
    if (fp == NULL) {
        perror("file error");
        exit(-1);
    }
    LinkList *i;
    for(i = head->next; i != NULL; i = i->next){
        fwrite(&(i->student1), sizeof(student) , 1, fp);
    }
    fclose(fp);
}

void SortNodeById(LinkList* head) {
    LinkList *pb, *pf, temp;
    pf = head;
    if(head == NULL) {//����Ϊ��
        printf("needn't order.\n");
        return ;
    }
    if(head->next == NULL) {//������1���ڵ�
        printf("only one print, needn't order.\n");
        return ;
    }
    while(pf->next != NULL) {//��pfָ��Ľڵ�Ϊ��׼�ڵ�
        pb = pf->next;//pb�ӻ�׼�����һ���ڵ㿪ʼ
        while(pb != NULL) {
            if(strcmp(pf->student1.id , pb->student1.id) > 0) {
                temp = *pf;
                *pf = *pb;
                *pb = temp;
                temp.next = pf->next;
                pf->next = pb->next;
                pb->next = temp.next;
            }
            pb = pb->next;
        }
        pf = pf->next;
    }
}
void SortNodeByIdDown(LinkList* head) {
    LinkList *pb, *pf, temp;
    pf = head;
    if(head == NULL) {//����Ϊ��
        printf("needn't order.\n");
        return ;
    }
    if(head->next == NULL) {//������1���ڵ�
        printf("only one print, needn't order.\n");
        return ;
    }
    while(pf->next != NULL) {//��pfָ��Ľڵ�Ϊ��׼�ڵ�
        pb = pf->next;//pb�ӻ�׼�����һ���ڵ㿪ʼ
        while(pb != NULL) {
            if(strcmp(pf->student1.id , pb->student1.id) < 0) {
                temp = *pf;
                *pf = *pb;
                *pb = temp;
                temp.next = pf->next;
                pf->next = pb->next;
                pb->next = temp.next;
            }
            pb = pb->next;
        }
        pf = pf->next;
    }
}
void AddNewStudent() {
    FILE *fp;
    fp=fopen("E:\\drom.txt","rb+");
    int flag = 0 ;
    if (fp == NULL) {
        perror("file error");
        exit(-1);
    }
    char id[23];
    student stu2, stu3;
    printf("\t����ѧ��:");
    fflush(stdin);
    scanf("%s", id);
    getchar();
    strcpy(stu3.id,id);
    printf("\t��������:");
    gets(stu3.name);
    printf("\t���빫Ԣ����:");
    scanf("%s",stu3.dorm);
    printf("\t������������:");
    scanf("%d",&(stu3.dormNum));
    printf("\t���봲λ��:");
    scanf("%d",&(stu3.dormNumId));
    printf("\t�ֻ���:");
    fflush(stdin);
    gets(stu3.number);
    printf("\t����:");
    scanf("%d",&(stu3.age));
    printf("\t�Ա�:");
    scanf("%s",stu3.sex);
    printf("\tרҵ�༶:");
    scanf("%s",stu3.major);
    while (fread(&stu2,sizeof(stu2), 1, fp)) {
        if (strcmp(id, stu2.id) == 0) {
            flag = 1;
        }
    }
    if (flag == 1 ) {
        printf("ѧ���Ѵ���");
    } else {
        fwrite(&stu3, sizeof(stu3), 1, fp);
        printf("���ӳɹ�");
        fclose(fp);
    }
}
int DeleteStudent(char* id){
    FILE *fp;
    fp=fopen("E:\\drom.txt","rb+");
    FILE* fp1 = fopen("E:\\coke.txt","wb+");
    int flag = 0 ;
    if (fp == NULL || fp1 == NULL) {
        perror("file error");
        exit(-1);
    }
    student stu2, stu3;
    while (fread(&stu2,sizeof(stu2), 1, fp)) {
        if (strcmp(id, stu2.id) != 0) {
            fwrite(&stu2, sizeof(student), 1, fp1);
        }
        else {
            flag = 1;
        }
    }
    fclose(fp);
    fclose(fp1);
    fp1 = fopen("E:\\coke.txt","rb+");
    fp = fopen("E:\\drom.txt","wb+");
    while (fread(&stu2,sizeof(stu2), 1, fp1)) {
        if (strcmp(id, stu2.id) != 0) {
            fwrite(&stu2, sizeof(student), 1, fp);
        }
    }
    fclose(fp);
    fclose(fp1);
    if (flag == 1) {
        printf("ɾ��ѧ���ɹ�\n");
        return 1;
    }
    else {
        printf("��ѧ��ѧ�Ų�����\n");
        return 0;
    }
}
int SearchStudent(char* id) {
    FILE* fp = fopen("E:\\drom.txt","rb+");
    if (fp == NULL) {
        perror("file error");
        exit(-1);
    }
    int flag = 0;
    int chas = 0;
    student student1;
    while (fread(&student1, sizeof(student1), 1, fp) > 0){
        if (strcmp(id, student1.id) == 0) {
            flag = 1;
            if (chas == 0) {
                printf("| %-10s | %-8s | %-9s | %-10s | %-7s | %-9s | %-5s | %-4s | %-12s |\n",
                       "ID", "Name", "Major", "Dorm", "DormNum", "DormNumId", "Sex", "Age", "Number");
                chas = 1;
                printf("----------------------------------------------------------------------------------\n");
            }
            printf("| %-10s | %-8s | %-9s | %-10s | %-7d | %-9d | %-5s | %-4d | %-12s |\n",
                   student1.id, student1.name, student1.major, student1.dorm, student1.dormNum,
                   student1.dormNumId, student1.sex, student1.age, student1.number);
        }
    }
    if (flag == 0) {
        printf("δ��ѯ����ѧ����Ϣ");
    }
}
int SearchStudentName(char* name) {
    FILE* fp = fopen("E:\\drom.txt","rb+");
    if (fp == NULL) {
        perror("file error");
        exit(-1);
    }
    int flag = 0;
    int chas = 0;
    student student1;
    while (fread(&student1, sizeof(student1), 1, fp)){
        if (strcmp(name, student1.name) == 0) {
            flag = 1;
            if (chas == 0) {
                printf("| %-10s | %-8s | %-9s | %-10s | %-7s | %-9s | %-5s | %-4s | %-12s |\n",
                       "ID", "Name", "Major", "Dorm", "DormNum", "DormNumId", "Sex", "Age", "Number");
                chas = 1;
                printf("----------------------------------------------------------------------------------\n");
            }
            printf("| %-10s | %-8s | %-9s | %-10s | %-7d | %-9d | %-5s | %-4d | %-12s |\n",
                   student1.id, student1.name, student1.major, student1.dorm, student1.dormNum,
                   student1.dormNumId, student1.sex, student1.age, student1.number);
        }
    }
    if (flag == 0) {
        printf("δ��ѯ����ѧ����Ϣ");
    }
}
int SearchStudentDrom(char* drom , int num) {
    FILE* fp = fopen("E:\\drom.txt","rb+");
    if (fp == NULL) {
        perror("file error");
        exit(-1);
    }
    int flag = 0;
    int chas = 0;
    student student1;
    while (fread(&student1, sizeof(student1), 1, fp)){
        if (strcmp(drom, student1.dorm) == 0 && num == student1.dormNum) {
            flag = 1;
            if (chas == 0) {
                printf("| %-10s | %-8s | %-9s | %-10s | %-7s | %-9s | %-5s | %-4s | %-12s |\n",
                       "ID", "Name", "Major", "Dorm", "DormNum", "DormNumId", "Sex", "Age", "Number");
                printf("----------------------------------------------------------------------------------\n");
                chas = 1;
            }
            printf("| %-10s | %-8s | %-9s | %-10s | %-5d | %-5d | %-5s | %-5d | %-12s |\n",
                   student1.id, student1.name, student1.major, student1.dorm, student1.dormNum,
                   student1.dormNumId, student1.sex, student1.age, student1.number);
        }
    }
    if (flag == 0) {
        printf("δ��ѯ����ѧ����Ϣ");
    }
}
int ModifyStudent(char* id) {
    FILE* fp = fopen("E:\\drom.txt", "rb+");
    if (fp == NULL) {
        perror("file error");
        exit(-1);
    }

    student student1;
    int found = 0;
    while (fread(&student1, sizeof(student1), 1, fp) > 0) {
        if (strcmp(id, student1.id) == 0) {
            found = 1;
            printf("��������Ҫ�޸ĵ�����\n");
            printf("1. �޸�ѧ��\n2. �޸Ĺ�Ԣ\n3. �޸Ĵ���\n4. �޸������\n");
            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("�������µ�ѧ��: ");
                    scanf("%s", student1.id);
                    break;
                case 2:
                    printf("�������µĹ�Ԣ: ");
                    scanf("%s", student1.dorm);
                    break;
                case 3:
                    printf("�������µĴ���: ");
                    scanf("%d", &(student1.dormNumId));
                    break;
                case 4:
                    printf("�������µ������: ");
                    scanf("%d", &(student1.dormNum));
                    break;
                default:
                    printf("��Ч��ѡ��\n");
                    break;
            }

            // ���ļ�ָ�붨λ����ǰѧ����Ϣ��λ��
            fseek(fp, -sizeof(student1), SEEK_CUR);
            // ���޸ĺ��ѧ����Ϣд���ļ�
            fwrite(&student1, sizeof(student1), 1, fp);

            printf("�޸ĳɹ�\n");
            break; // �ҵ����޸���ѧ����Ϣ������ѭ��
        }
    }

    if (!found) {
        printf("δ�ҵ�ѧ����Ϣ\n");
    }

    fclose(fp);
    return found;
}

void interface1() {

        printf("\t\t------------------\n");
        printf("\t\t|1.��ѧ�Ų�ѯ    |\n");
        printf("\t\t|2.��������ѯ    |\n");
        printf("\t\t|3.����Ԣ�����ѯ|\n");
        printf("\t\t------------------\n");
}
void initInterface() {
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
    printf("\t|\t\t\t8-�˳�ϵͳ\t\t\t|\n");
    printf("\t---------------------------------------------------------\n");
}
int SelectMenu() {
    int choice;
    int status;
    int flag = 1;
    char id[20];
    while (flag) {
        int tmp = 1;
        initInterface();
        LinkList *head;
        head = ReadLinkList();
        printf("\t����1~7��");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1://¼����Ϣ
                system("cls");
                status = 1;
                while (status) {
                    head = CreatList();//��������
                    WriteLinkList(head);//д���ļ�
                    printf("\n");
                    printf("����0������һ��\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 2://����
                system("cls");
                status = 1;
                while (status) {
                    AddNewStudent();
                    printf("\n");
                    printf("����0������һ��\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 3://��ѧ��ɾ��
                system("cls");
                status = 1;
                while (status) {
                    printf("������Ҫɾ����ѧ��");
                    gets(id);
                    DeleteStudent(id);
                    printf("\n");
                    printf("����0������һ��\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 4://�İ�ѧ��
                system("cls");
                status = 1;
                while (status) {
                    printf("������Ҫ�޸ĵ�ѧ����ѧ��");
                    scanf("%s", id);
                    getchar();
                    ModifyStudent(id);
                    printf("\n");
                    printf("����0������һ��\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 5://�飬�����������ᣬѧ��
                system("cls");//��Ŀ¼
                status = 1;
                while (status) {
                    SonOperation(head);
                    printf("\n");
                    printf("����0������һ��\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 6: //ͳ�ƣ���������ÿ������������һ��¥����
                system("cls");//��Ŀ¼
                status = 1;
                while (status) {
                    StatisticalOperation(head);
                    printf("\n");
                    printf("����0������һ��\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 7://����
                system("cls");
                status = 1;
                while (status) {
                    while (tmp) {
                        printf("������������ķ�ʽ\n");
                        printf("��ѡ����Ҫ�����˳��\n1. ���� 2. ����\n");
                        switch (getchar()) {
                            case '1':
                                SortNodeById(head);
                                tmp = 0;
                                system("cls");
                                break;
                            case '2':
                                SortNodeByIdDown(head);
                                system("cls");
                                tmp = 0;
                                break;
                            default:
                                printf("����������");
                                tmp = 1;
                                break;
                        }
                    }
                    printf("\t---------------------------------------------------------------------------------\n");
                    Print(head);
                    printf("\t---------------------------------------------------------------------------------\n");
                    printf("\n");
                    printf("����0������һ��\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 8:
                flag = 0;
            default :
                system("cls");
                printf("\t->��������,��������<-\n");
                break;
        }
    }
    return 0;
}
void SonOperation(LinkList *head){//��ѯ����ѡ���
    interface1();
    printf("\t����ѡ��(0�˳�):");
    int choice;
    scanf("%d",&choice);
    getchar();
    if(choice == 0){
        return;
    }
    switch(choice){
        case 1:{
            char id[23];
            printf("����������˺�");
            scanf("%s", id);
            SearchStudent(id);//��id��ѯ
            break;
        }
        case 2:{
            char name[23];
            printf("�������������");
            scanf("%s", name);
            SearchStudentName(name);
            //��������ѯ
            break;
        }
        case 3:{
            char drom[23];
            int num;
            printf("��������Ĺ�Ԣ�������");
            scanf("%s %d",drom, &num);
            getchar();
            SearchStudentDrom(drom, num);//����Ԣ�����ѯ
            break;
        }
        default :{
            printf("\t->�����ʽ����<-\n");
            break;
        }
    }
}
void  StatisticalTotal(LinkList *head){//ͳ��������
    LinkList *i;
    int n = 0;
    for(i = head->next;i != NULL;i = i->next) {
        n++;
    }
    printf("\t->��%d��<-\n",n);
}
void StatisticalDorm(LinkList *head)//ͳ�Ƶ�����Ԣ
{
    int n=0;
    char dorm[20];
    printf("\t���빫Ԣ:");
    scanf("%s", dorm);
    getchar();
    LinkList *i;
    i=head;
    n=0;
    while((i=i->next)!=NULL){
        if(strcmp(dorm,i->student1.dorm)==0){
            n++;
        }
    }
    printf("\t->�ù�Ԣ��%d��<-\n",n);
}
void StatisticalDormNum(LinkList *head)//ͳ�ƹ�Ԣ����
{
    int  num=0;
    int n;
    char dorm[20];
    printf("\t���빫Ԣ�������:");
    scanf("%s %d",dorm, &num);
    getchar();
    LinkList *i;
    n=0;
    i=head;
    while((i = i->next)!=NULL){
        if(num == (i->student1.dormNum)&&strcmp(dorm, i->student1.dorm)==0){
            n++;
        }
    }
    printf("\t->�����Ṥ%d��<-\n",n);
    num=0;
}
void StatisticalOperation(LinkList *head) //ͳ�Ʋ���ѡ���
{
    SonStatistical();
    printf("\t����ѡ��(0�˳�):");
    int choice;
    scanf("%d",&choice);
    getchar();
    if(choice==0)
    {
        return;
    }
    switch(choice)
    {
        case 1:{
            StatisticalTotal(head);//ͳ��������
            break;
        }
        case 2:{
            StatisticalDorm(head);//ͳ�Ƶ�����Ԣ
            break;
        }
        case 3:{
            StatisticalDormNum(head);//ͳ�ƹ�Ԣ����
            break;
        }
        default :{
            printf("\t->�����ʽ����<-\n");
            break;
        }
    }
}
void SonStatistical()//ͳ�Ʋ�������Ŀ¼
{
    printf("\t\t----------------\n");
    printf("\t\t----------------\n");
    printf("\t\t----------------\n");
    printf("\t\t|1.ͳ��������  |\n");
    printf("\t\t|2.ͳ�Ƶ�����Ԣ|\n");
    printf("\t\t|3.ͳ�ƹ�Ԣ����|\n");
    printf("\t\t----------------\n");
}
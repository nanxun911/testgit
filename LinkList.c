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
    scanf("%s", id);
    getchar();
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
LinkList * ReadLinkList(){//读取文件
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
    if(head == NULL) {//链表为空
        printf("needn't order.\n");
        return ;
    }
    if(head->next == NULL) {//链表有1个节点
        printf("only one print, needn't order.\n");
        return ;
    }
    while(pf->next != NULL) {//以pf指向的节点为基准节点
        pb = pf->next;//pb从基准点的下一个节点开始
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
    if(head == NULL) {//链表为空
        printf("needn't order.\n");
        return ;
    }
    if(head->next == NULL) {//链表有1个节点
        printf("only one print, needn't order.\n");
        return ;
    }
    while(pf->next != NULL) {//以pf指向的节点为基准节点
        pb = pf->next;//pb从基准点的下一个节点开始
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
    printf("\t输入学号:");
    fflush(stdin);
    scanf("%s", id);
    getchar();
    strcpy(stu3.id,id);
    printf("\t输入姓名:");
    gets(stu3.name);
    printf("\t输入公寓名称:");
    scanf("%s",stu3.dorm);
    printf("\t输入宿舍名称:");
    scanf("%d",&(stu3.dormNum));
    printf("\t输入床位号:");
    scanf("%d",&(stu3.dormNumId));
    printf("\t手机号:");
    fflush(stdin);
    gets(stu3.number);
    printf("\t年龄:");
    scanf("%d",&(stu3.age));
    printf("\t性别:");
    scanf("%s",stu3.sex);
    printf("\t专业班级:");
    scanf("%s",stu3.major);
    while (fread(&stu2,sizeof(stu2), 1, fp)) {
        if (strcmp(id, stu2.id) == 0) {
            flag = 1;
        }
    }
    if (flag == 1 ) {
        printf("学号已存在");
    } else {
        fwrite(&stu3, sizeof(stu3), 1, fp);
        printf("增加成功");
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
        printf("删除学生成功\n");
        return 1;
    }
    else {
        printf("该学生学号不存在\n");
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
        printf("未查询到该学生信息");
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
        printf("未查询到该学生信息");
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
        printf("未查询到该学生信息");
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
            printf("请输入你要修改的内容\n");
            printf("1. 修改学号\n2. 修改公寓\n3. 修改床号\n4. 修改宿舍号\n");
            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("请输入新的学号: ");
                    scanf("%s", student1.id);
                    break;
                case 2:
                    printf("请输入新的公寓: ");
                    scanf("%s", student1.dorm);
                    break;
                case 3:
                    printf("请输入新的床号: ");
                    scanf("%d", &(student1.dormNumId));
                    break;
                case 4:
                    printf("请输入新的宿舍号: ");
                    scanf("%d", &(student1.dormNum));
                    break;
                default:
                    printf("无效的选项\n");
                    break;
            }

            // 将文件指针定位到当前学生信息的位置
            fseek(fp, -sizeof(student1), SEEK_CUR);
            // 将修改后的学生信息写回文件
            fwrite(&student1, sizeof(student1), 1, fp);

            printf("修改成功\n");
            break; // 找到并修改了学生信息，跳出循环
        }
    }

    if (!found) {
        printf("未找到学生信息\n");
    }

    fclose(fp);
    return found;
}

void interface1() {

        printf("\t\t------------------\n");
        printf("\t\t|1.按学号查询    |\n");
        printf("\t\t|2.按姓名查询    |\n");
        printf("\t\t|3.按公寓宿舍查询|\n");
        printf("\t\t------------------\n");
}
void initInterface() {
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
    printf("\t|\t\t\t8-退出系统\t\t\t|\n");
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
        printf("\t输入1~7：");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1://录入信息
                system("cls");
                status = 1;
                while (status) {
                    head = CreatList();//创建链表
                    WriteLinkList(head);//写入文件
                    printf("\n");
                    printf("输入0返回上一层\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 2://增加
                system("cls");
                status = 1;
                while (status) {
                    AddNewStudent();
                    printf("\n");
                    printf("输入0返回上一层\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 3://按学号删除
                system("cls");
                status = 1;
                while (status) {
                    printf("输入你要删除的学号");
                    gets(id);
                    DeleteStudent(id);
                    printf("\n");
                    printf("输入0返回上一层\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 4://改按学号
                system("cls");
                status = 1;
                while (status) {
                    printf("输入你要修改的学生的学号");
                    scanf("%s", id);
                    getchar();
                    ModifyStudent(id);
                    printf("\n");
                    printf("输入0返回上一层\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 5://查，按姓名，宿舍，学号
                system("cls");//子目录
                status = 1;
                while (status) {
                    SonOperation(head);
                    printf("\n");
                    printf("输入0返回上一层\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 6: //统计，总人数，每个宿舍人数，一个楼人数
                system("cls");//子目录
                status = 1;
                while (status) {
                    StatisticalOperation(head);
                    printf("\n");
                    printf("输入0返回上一层\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 7://报表
                system("cls");
                status = 1;
                while (status) {
                    while (tmp) {
                        printf("请输入你输出的方式\n");
                        printf("清选择你要输出的顺序\n1. 升序 2. 降序\n");
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
                                printf("请重新输入");
                                tmp = 1;
                                break;
                        }
                    }
                    printf("\t---------------------------------------------------------------------------------\n");
                    Print(head);
                    printf("\t---------------------------------------------------------------------------------\n");
                    printf("\n");
                    printf("输入0返回上一层\n");
                    scanf("%d", &status);
                }
                system("cls");
                break;
            case 8:
                flag = 0;
            default :
                system("cls");
                printf("\t->输入有误,重新输入<-\n");
                break;
        }
    }
    return 0;
}
void SonOperation(LinkList *head){//查询操作选项表
    interface1();
    printf("\t输入选项(0退出):");
    int choice;
    scanf("%d",&choice);
    getchar();
    if(choice == 0){
        return;
    }
    switch(choice){
        case 1:{
            char id[23];
            printf("请输入你的账号");
            scanf("%s", id);
            SearchStudent(id);//按id查询
            break;
        }
        case 2:{
            char name[23];
            printf("请输入你的姓名");
            scanf("%s", name);
            SearchStudentName(name);
            //按姓名查询
            break;
        }
        case 3:{
            char drom[23];
            int num;
            printf("请输入你的公寓和宿舍号");
            scanf("%s %d",drom, &num);
            getchar();
            SearchStudentDrom(drom, num);//按公寓宿舍查询
            break;
        }
        default :{
            printf("\t->输入格式有误<-\n");
            break;
        }
    }
}
void  StatisticalTotal(LinkList *head){//统计总人数
    LinkList *i;
    int n = 0;
    for(i = head->next;i != NULL;i = i->next) {
        n++;
    }
    printf("\t->共%d人<-\n",n);
}
void StatisticalDorm(LinkList *head)//统计单个公寓
{
    int n=0;
    char dorm[20];
    printf("\t输入公寓:");
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
    printf("\t->该公寓共%d人<-\n",n);
}
void StatisticalDormNum(LinkList *head)//统计公寓宿舍
{
    int  num=0;
    int n;
    char dorm[20];
    printf("\t输入公寓和宿舍号:");
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
    printf("\t->该宿舍工%d人<-\n",n);
    num=0;
}
void StatisticalOperation(LinkList *head) //统计操作选项表
{
    SonStatistical();
    printf("\t输入选项(0退出):");
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
            StatisticalTotal(head);//统计总人数
            break;
        }
        case 2:{
            StatisticalDorm(head);//统计单个公寓
            break;
        }
        case 3:{
            StatisticalDormNum(head);//统计公寓宿舍
            break;
        }
        default :{
            printf("\t->输入格式有误<-\n");
            break;
        }
    }
}
void SonStatistical()//统计操作表子目录
{
    printf("\t\t----------------\n");
    printf("\t\t----------------\n");
    printf("\t\t----------------\n");
    printf("\t\t|1.统计总人数  |\n");
    printf("\t\t|2.统计单个公寓|\n");
    printf("\t\t|3.统计公寓宿舍|\n");
    printf("\t\t----------------\n");
}
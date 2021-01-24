#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct link{
	char studentname[10];
    char number[10];
	int age;
	int grade;
	struct link*next;
};
struct name{
	char studentname[10];
    char number[10];
	int age;
	int grade;  
 };
 int count=0; 
 void input()
{
	struct name stus[100];
	FILE *fp;
	fp=fopen("stulnfo.txt","a+");
	if(fp==NULL)
	{
		printf("打开文件失败，请重试！\n");
		fclose(fp);
		exit(0);
	}
	char c;
	int i=0;
	 printf("请输入全部学生的名字，学号，年龄，c语言成绩。\n");
	while(1)
	{
		printf("********第%d个学生********\n",i+1);
		printf("姓名：");
		scanf("%s",&stus[i].studentname);
		printf("学号：");
		scanf("%s",&stus[i].number);
		printf("年龄：");
		scanf("%d",&stus[i].age);
		printf("C语言成绩：");
		scanf("%d",&stus[i].grade); 
		fprintf(fp,"%s %s %d %d\n",stus[i].studentname,stus[i].number,stus[i].age,stus[i].grade);
		printf("添加学生成功，请按任意键返回!(停止输入请按CTRL+z)\n");
		getchar();
		c=getchar();
		i++;
		count++;
		if(c==EOF)
		break;
	}
	fclose(fp);
}
void swap(char *str1,char *str2)
{
char temp[10];
strcpy(temp,str1);
strcpy(str1,str2);
strcpy(str2,temp);
return;
}
void print()
{
	struct name stus[100];
	int i=0;
	printf("成绩信息如下：\n");
	FILE *fp;
	fp=fopen("stulnfo.txt","r");
	if(fp==NULL)
	{
		printf("打开文件失败，请重试！\n");
		fclose(fp);
		exit(0);
	}
	printf("姓名\t学号\t\t年龄\tc语言成绩\t\n");
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %d %d\n",&stus[i].studentname,&stus[i].number,&stus[i].age,&stus[i].grade);
		printf("%s\t%s\t%d\t%d\t\n",stus[i].studentname,stus[i].number,stus[i].age,stus[i].grade); 
		i++;
	}
	fclose(fp);
	printf("显示完毕\n");
	return ; 
 }
 void change(struct link*head,int n)
 {
 	 struct link*node=head;  
   int i;
   for(i=0;i<n;i++)   
 {
 	node=node->next;
 }
 printf("找到该同学的成绩:%d，请输入你要修改的新成绩：",node->grade);
 scanf("%d",&node->grade);
 return ;
 }
 int find(struct link*head)
 {
    struct link*node=head->next;  
    int i=1;
    char n;
    char findname[10];
    printf("请选择你要查找的方式\n");
    printf("1:姓名查询 2：学号查询\n");
    scanf("%c",&n);
    if(n=='\n')
    n=getchar();
 	switch(n)
 	{
 		case '1':
 	    printf("请输入你要查找的姓名\n");
		scanf("%s",&findname);
 		 while	(node!=NULL)
	 {
	 	if(strcmp(findname,node->studentname)==0)
	 	{
	 		printf("姓名：%s\n",node->studentname);
	 		printf("学号：%s\n",node->number);
	 		printf("年龄：%d\n",node->age);
	 		printf("成绩: %d\n",node->grade);
	 		return i;
		 }
		 node=node->next; 
		 i++;
	  } 
	  break;
	case '2':
		 printf("请输入你要查找的学号\n");
		 scanf("%s",&findname);
 		 while	(node!=NULL)
	 {
	 	if(strcmp(findname,node->number)==0)
	 	{
	 		printf("姓名：%s\n",node->studentname);
	 		printf("学号：%s\n",node->number);
	 		printf("年龄：%d\n",node->age);
	 		printf("成绩: %d\n",node->grade);
	 		return i;
		 }
		 node=node->next;
		 i++;
	  } 
	   break;
	default:
	printf("输入错误\n");
	return 0; 
	 }
 printf("未找到该同学信息!\n");
 return 0;
 }
struct link* create()
 {
 	FILE *fp;
 	fp=fopen("stulnfo.txt","r");
 	if(fp==NULL)
 	{
 		printf("打开文件失败！\n");
 		exit(0);
	 }
	 struct link*head,*prev,*node;
	 head=(struct link*)malloc(sizeof(struct link));
	 head->next=NULL;
	 prev=head;
	 while(!feof(fp))
	 {
	 	node=(struct link*)malloc(sizeof(struct link));
	 	prev->next=node;
	 	prev=node;
	 	fscanf(fp,"%s %s %d %d\n",&node->studentname,&node->number,&node->age,&node->grade);
	 }
	 node->next=NULL;
	 fclose(fp);
	 return head;
 }
 void delet(struct link*head,int n)
 {
 	int i;
    struct link*node=head;
	for( i=0;i<n-1;i++)
	{
		node=node->next;
	}
	struct link*a,*b;
	a=node->next;
	b=a->next;
	node->next=b;
	free(a);
	printf("删除成功!\n");
  } 
  void insert(struct link*head)
{
	int i;        
	struct link*a,*b;   
    struct link*node=head;
		a=node->next;
		node->next=(struct link*)malloc(sizeof(struct link));
		b=node->next;
		b->next=a;
		printf("姓名：");
		scanf("%s",&b->studentname);
		printf("学号："); 
		scanf("%s",&b->number);
		printf("年龄：");
		scanf("%d",&b->age);
		printf("成绩：");
		scanf("%d",&b->grade);
		printf("插入成功!\n"); 
		return;	
}
  void write(struct link*head)
  {
  	FILE *fp;
  	fp=fopen("stulnfo.txt","w");
  	if(fp==NULL)
  	{
  		printf("打开文件失败!\n");
  		exit(0);
	  }
  	struct link*node=head->next;
  	while(node!=NULL)
  	{
       fprintf(fp,"%s %s %d %d\n",node->studentname,node->number,node->age,node->grade);
	   node=node->next;  		
	  }
	  fclose(fp);
	  return;
  }
void sort(struct link*head)
{
	int temp;
	struct link*a,*b,*tail;
    a=head->next;
    b=a->next;
    tail=NULL;
    if(a==NULL||a->next==NULL)
    return;
	while(a!=tail)
	{
		while(a->next!=tail) 
		{
			if(a->grade>b->grade)
			{
		     swap(a->studentname,b->studentname);
			 swap(a->number,b->number);
			 temp=a->age;
			 a->age=b->age;
			 b->age=temp;
			 temp=a->grade;
			 a->grade=b->grade;
			 b->grade=temp;		
			}
			a=a->next;
			b=b->next;
		}
		tail=a;
		a=head->next;
		b=a->next; 
	}
}
int main()
{
	int k,i;
	char chance,a,count;
	struct link*head;
	char username[10];
	char password[10];
printf("*****************************\n");
printf("      学生证管理系统\n");
printf("使用须知：\n");
printf("1:学号为八位学号，请勿输错。\n");
printf("2:对应输入应按正确格式输入。\n");
system("pause");	
system("cls");
head=create();
while(1)
{ 
printf("请选择登录模式：\n"); 
printf("1：学生登录\n");
printf("2: 教师登录\n");
scanf("%c",&chance);
system("pause");
system("cls");
getchar();
if(chance=='1')
{
	int flag=0;
	char username[10];
	char password[10];
	char usernames[10];
	char passwords[10];
	while(1){
	printf("账号："); 
	gets(username);
	printf("密码：");
	gets(password);
	FILE *fp;
	fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("打开文件失败！\n");
		exit(0);
	}
	while(!feof(fp))
 	{   
		fscanf(fp,"%s %s\n",usernames,passwords);
		if(strcmp(username,usernames)==0)
		{
			if(strcmp(password,passwords)==0)
			{
			   flag=1;
			   break;	
			}
	}}
	fclose(fp);
	if(flag==1)
	{
		printf("登录成功！\n");
		break;
	}
	else
	printf("登录失败，请重试！\n");
	}
	system("pause");
	system("cls");
	while(1)
	{
	printf("1:显示全部学生成绩。\n");
	printf("2:查找单个学生成绩.\n");
	scanf("%c",&a);
	if(a=='\n')
	a=getchar();
	switch(a)
	{
		case '1':
		sort(head);
		write(head);
		print();
		break;
		case '2':
		while(1)
		{
			k=find(head);
			if(k!=0)
			break;
			}	
		break;
	default:
	printf("输入错误！\n");
	continue;	
	}
	char c;
    printf("按任意键继续(退出请按CTRL+z)!\n"); 
    c=getchar() ;
    if(c=='\n')
	c=getchar(); 
	if(c==EOF)
    return 0;
    system("pause");
	system("cls");
	} 
}
else if(chance=='2')
{ 
int flag=0;
	char username[10];
	char password[10];
	char usernames[10];
	char passwords[10];
	while(1){
	printf("账号："); 
	gets(username);
	printf("密码：");
	gets(password);
	FILE *fp;
	fp=fopen("teacher.txt","r");
	if(fp==NULL)
	{
		printf("打开文件失败！\n");
		exit(0);
	}
	while(!feof(fp))
 	{   
		fscanf(fp,"%s %s\n",usernames,passwords);
		if(strcmp(username,usernames)==0)
		{
			if(strcmp(password,passwords)==0)
			{
			   flag=1;
			   break;	
			}
	}}
	fclose(fp);
	if(flag==1)
	{
		printf("登录成功！\n");
		break;
	}
	else
	printf("登录失败，请重试！\n");
	}
	system("pause");
	system("cls");
while(1)
{
printf("请选择需要执行的功能：\n");
printf("1:录入多个学生数据\n");
printf("2:查询单个学生数据\n");
printf("3:按成绩降序显示学生数据\n");
printf("4:删除单个学生数据\n");
printf("5:增加单个学生数据\n");
printf("6:修改某个学生数据\n");
scanf("%c",&count);
if(count=='\n')
count=getchar();
switch(count)
{
	case '1':
	input();
	head=create();
	break;
	case '2':
	while(1)
    {
    	k=find(head);
    	if(k!=0)
    	break;
	}
	break;
	case '3':
	sort(head);
	write(head);
	print();
	break;
	case '4':
		while(1)
		{
			k=find(head);
			if(k!=0)
			break;
		}
	delet(head,k);
	write(head);
	break;
	case '5':
	insert(head);
	write(head);
	break;
	case '6':
	while(1)
	{
		k=find(head);
		if(k!=0)
		break;
	}
	change(head,k);
	write(head);
	break;
	default:
		printf("输入错误！\n");
		continue;
 }
 system("pause");
 system("cls"); 
 char c;
 printf("按任意键继续(退出请按CTRL+z)!\n");
c=getchar() ;
if(c=='\n')
c=getchar();
if(c==EOF)
 return 0;
}
}
else
{
	printf("输入失败!\n");
	continue;
}
 } 
}


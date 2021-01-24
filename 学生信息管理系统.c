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
		printf("���ļ�ʧ�ܣ������ԣ�\n");
		fclose(fp);
		exit(0);
	}
	char c;
	int i=0;
	 printf("������ȫ��ѧ�������֣�ѧ�ţ����䣬c���Գɼ���\n");
	while(1)
	{
		printf("********��%d��ѧ��********\n",i+1);
		printf("������");
		scanf("%s",&stus[i].studentname);
		printf("ѧ�ţ�");
		scanf("%s",&stus[i].number);
		printf("���䣺");
		scanf("%d",&stus[i].age);
		printf("C���Գɼ���");
		scanf("%d",&stus[i].grade); 
		fprintf(fp,"%s %s %d %d\n",stus[i].studentname,stus[i].number,stus[i].age,stus[i].grade);
		printf("���ѧ���ɹ����밴���������!(ֹͣ�����밴CTRL+z)\n");
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
	printf("�ɼ���Ϣ���£�\n");
	FILE *fp;
	fp=fopen("stulnfo.txt","r");
	if(fp==NULL)
	{
		printf("���ļ�ʧ�ܣ������ԣ�\n");
		fclose(fp);
		exit(0);
	}
	printf("����\tѧ��\t\t����\tc���Գɼ�\t\n");
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %d %d\n",&stus[i].studentname,&stus[i].number,&stus[i].age,&stus[i].grade);
		printf("%s\t%s\t%d\t%d\t\n",stus[i].studentname,stus[i].number,stus[i].age,stus[i].grade); 
		i++;
	}
	fclose(fp);
	printf("��ʾ���\n");
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
 printf("�ҵ���ͬѧ�ĳɼ�:%d����������Ҫ�޸ĵ��³ɼ���",node->grade);
 scanf("%d",&node->grade);
 return ;
 }
 int find(struct link*head)
 {
    struct link*node=head->next;  
    int i=1;
    char n;
    char findname[10];
    printf("��ѡ����Ҫ���ҵķ�ʽ\n");
    printf("1:������ѯ 2��ѧ�Ų�ѯ\n");
    scanf("%c",&n);
    if(n=='\n')
    n=getchar();
 	switch(n)
 	{
 		case '1':
 	    printf("��������Ҫ���ҵ�����\n");
		scanf("%s",&findname);
 		 while	(node!=NULL)
	 {
	 	if(strcmp(findname,node->studentname)==0)
	 	{
	 		printf("������%s\n",node->studentname);
	 		printf("ѧ�ţ�%s\n",node->number);
	 		printf("���䣺%d\n",node->age);
	 		printf("�ɼ�: %d\n",node->grade);
	 		return i;
		 }
		 node=node->next; 
		 i++;
	  } 
	  break;
	case '2':
		 printf("��������Ҫ���ҵ�ѧ��\n");
		 scanf("%s",&findname);
 		 while	(node!=NULL)
	 {
	 	if(strcmp(findname,node->number)==0)
	 	{
	 		printf("������%s\n",node->studentname);
	 		printf("ѧ�ţ�%s\n",node->number);
	 		printf("���䣺%d\n",node->age);
	 		printf("�ɼ�: %d\n",node->grade);
	 		return i;
		 }
		 node=node->next;
		 i++;
	  } 
	   break;
	default:
	printf("�������\n");
	return 0; 
	 }
 printf("δ�ҵ���ͬѧ��Ϣ!\n");
 return 0;
 }
struct link* create()
 {
 	FILE *fp;
 	fp=fopen("stulnfo.txt","r");
 	if(fp==NULL)
 	{
 		printf("���ļ�ʧ�ܣ�\n");
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
	printf("ɾ���ɹ�!\n");
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
		printf("������");
		scanf("%s",&b->studentname);
		printf("ѧ�ţ�"); 
		scanf("%s",&b->number);
		printf("���䣺");
		scanf("%d",&b->age);
		printf("�ɼ���");
		scanf("%d",&b->grade);
		printf("����ɹ�!\n"); 
		return;	
}
  void write(struct link*head)
  {
  	FILE *fp;
  	fp=fopen("stulnfo.txt","w");
  	if(fp==NULL)
  	{
  		printf("���ļ�ʧ��!\n");
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
printf("      ѧ��֤����ϵͳ\n");
printf("ʹ����֪��\n");
printf("1:ѧ��Ϊ��λѧ�ţ��������\n");
printf("2:��Ӧ����Ӧ����ȷ��ʽ���롣\n");
system("pause");	
system("cls");
head=create();
while(1)
{ 
printf("��ѡ���¼ģʽ��\n"); 
printf("1��ѧ����¼\n");
printf("2: ��ʦ��¼\n");
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
	printf("�˺ţ�"); 
	gets(username);
	printf("���룺");
	gets(password);
	FILE *fp;
	fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
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
		printf("��¼�ɹ���\n");
		break;
	}
	else
	printf("��¼ʧ�ܣ������ԣ�\n");
	}
	system("pause");
	system("cls");
	while(1)
	{
	printf("1:��ʾȫ��ѧ���ɼ���\n");
	printf("2:���ҵ���ѧ���ɼ�.\n");
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
	printf("�������\n");
	continue;	
	}
	char c;
    printf("�����������(�˳��밴CTRL+z)!\n"); 
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
	printf("�˺ţ�"); 
	gets(username);
	printf("���룺");
	gets(password);
	FILE *fp;
	fp=fopen("teacher.txt","r");
	if(fp==NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
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
		printf("��¼�ɹ���\n");
		break;
	}
	else
	printf("��¼ʧ�ܣ������ԣ�\n");
	}
	system("pause");
	system("cls");
while(1)
{
printf("��ѡ����Ҫִ�еĹ��ܣ�\n");
printf("1:¼����ѧ������\n");
printf("2:��ѯ����ѧ������\n");
printf("3:���ɼ�������ʾѧ������\n");
printf("4:ɾ������ѧ������\n");
printf("5:���ӵ���ѧ������\n");
printf("6:�޸�ĳ��ѧ������\n");
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
		printf("�������\n");
		continue;
 }
 system("pause");
 system("cls"); 
 char c;
 printf("�����������(�˳��밴CTRL+z)!\n");
c=getchar() ;
if(c=='\n')
c=getchar();
if(c==EOF)
 return 0;
}
}
else
{
	printf("����ʧ��!\n");
	continue;
}
 } 
}


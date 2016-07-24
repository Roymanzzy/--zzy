#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*************************************�û���Ϣ�ṹ��*************************************/
struct user{
	char name[10];
	int win,lose,ping,jwin;
}u;
/*************************************������******************** ***************/
int main()
{
	int com,user;                                                 /*com:���ԣ�user:���*/ 
	int n,i;                                                      /*n:��������i:ѭ������*/ 
	int win,lose,ping,jwin,total;                                 /*Ӯ�������������ƽ��������Ӯ�����ܾ���*/ 
	void judge(int *pwin,int *plose,int *pping,int *pjwin);      /*�жϺ�������*/
	struct user u[50];                                           /*����ṹ������u*/
	struct user input_user();                                    /*������㺯������*/ 
	void sort_user(struct user u[],int n);                       /*���а�������*/
	void output_user(struct user u[],int n);                     /*���а������������*/
	printf("��ӭ�μӼ���ʯͷ������\n");
	printf("��ѡ����Ϸģʽ��1.��ϰģʽ(������ʤ)    2.ʵ����սģʽ(������ʤ)\n",i);
	scanf("%d",&i);
/**********************************��ϰģʽ(������)*************************************/
	if(i==1)
	{
		printf("                ------------------------------------------------------------\n");
		printf("                |                      ��Ϸ����                            |\n");
		printf("                |                                                          |\n");
		printf("                |------��ҿɳ�����������ʯͷ������������֮һ������--------|\n");
		printf("                |                                                          |\n");
		printf("                -----------����>��     ��>ʯͷ    ʯͷ>����-----------------\n");
		printf("\n");
		judge(&win,&lose,&ping,&jwin);               /*�Զ����жϺ���*/
		total=win+lose+ping;
		printf("\n");
		printf("            ------------------------------------------------------------\n");
		printf("            |                                                          |\n");
		printf("            |----�����Ϣ��Ӯ%d�֣���%d�֣�ƽ%d�֣���Ӯ%d��,����%d��---|\n",win,lose,ping,jwin,total);
		printf("            |                                                          |\n");
		printf("            ---------------------------��ϰ����-------------------------\n");
	}
/*******************************ʵ����սģʽ(������)***********************************/
	else
	{
		printf("���������������\n");
		scanf("%d",&n);
		for(i=0;i<n;i++){
			printf("\n�������%d������ƣ�\n",i+1);
			u[i]=input_user();
			judge(&win,&lose,&ping,&jwin);
			u[i].win=win;u[i].lose=lose;u[i].ping=ping;u[i].jwin=jwin;            /*�Խṹ������ֱ�Ӹ�ֵ*/ 
		}sort_user(u,n);                                                         /*���򣺰���Ӯ�����ɴ�С����*/
		printf("\n"); 
		printf("\n----------------------------------������а�-----------------------------------\n");
		output_user(u,n);                                                         /*��������������Ϣ��¼*/ 
	}

}
/**********************************�û���Ϣ���뺯������***********************************/
struct user input_user()
{
	struct user u;
	printf("����:");
	scanf("%s",&u.name);
	return u;
};
/**********************************�ж���Ӯ�ĺ�������**********************************/
void judge(int *pwin,int *plose,int *pping,int *pjwin)
{
	int lose=0,win=0,ping=0,jwin=0;
	int user,com;
	do{
		printf("���ȭ(1.������2.ʯͷ��3.��):");
		scanf("%d",&user);
		srand((unsigned)time(NULL));
		com=rand()%3+1;
		printf("���Գ�%s\n",com==1?"����":com==2?"ʯͷ":"��");
		switch(com-user)
		{
			case 0:
			printf("--------ƽ��----------------\n");ping=ping+1;
			break;
			case 1:
			case -2:
			printf("--------����Ӯ��------------\n");lose=lose+1;
			break;
			case -1: 
			case 2:
			printf("--------��Ӯ��--------------\n");win=win+1;
			break;
			default:printf("Error!!!\n");break;
		}
	} while(!(win==2||lose==2));
	jwin=win-lose;
	*pwin=win;*plose=lose;*pping=ping;*pjwin=jwin;
}
/********************************************���а���������********************************************/
void sort_user(struct user u[],int n)
{
	int i,j,index;
	struct user temp;
	for(i=0;i<n-1;i++)
	{
		index=i;
		for(j=1;j<n;j++) if(u[j].jwin>u[index].jwin) index=j;
		temp=u[i];u[i]=u[index];u[index]=temp;
	}
}
/********************************************���а������������********************************************/
void output_user(struct user u[],int n)
{
	int i;
	printf("����  Ӯ����  �����  ƽ����  ��Ӯ����\n");
	for(i=0;i<n;i++)
	{
		printf("%-10s%-3d%-3d%-3d%-3d\n",u[i].name,u[i].win,u[i].lose,u[i].ping,u[i].jwin);
	}
}

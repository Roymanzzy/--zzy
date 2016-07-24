#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*************************************用户信息结构体*************************************/
struct user{
	char name[10];
	int win,lose,ping,jwin;
}u;
/*************************************主函数******************** ***************/
int main()
{
	int com,user;                                                 /*com:电脑，user:玩家*/ 
	int n,i;                                                      /*n:总人数。i:循环变量*/ 
	int win,lose,ping,jwin,total;                                 /*赢局数，输局数，平局数，净赢数，总局数*/ 
	void judge(int *pwin,int *plose,int *pping,int *pjwin);      /*判断函数声明*/
	struct user u[50];                                           /*定义结构体数组u*/
	struct user input_user();                                    /*输入计算函数声明*/ 
	void sort_user(struct user u[],int n);                       /*排行榜函数声明*/
	void output_user(struct user u[],int n);                     /*排行榜输出函数声明*/
	printf("欢迎参加剪刀石头布竞赛\n");
	printf("请选择游戏模式：1.练习模式(三局两胜)    2.实名对战模式(三局两胜)\n",i);
	scanf("%d",&i);
/**********************************练习模式(主函数)*************************************/
	if(i==1)
	{
		printf("                ------------------------------------------------------------\n");
		printf("                |                      游戏规则                            |\n");
		printf("                |                                                          |\n");
		printf("                |------玩家可出‘剪刀’‘石头’‘布’三种之一的手势--------|\n");
		printf("                |                                                          |\n");
		printf("                -----------剪刀>布     布>石头    石头>剪刀-----------------\n");
		printf("\n");
		judge(&win,&lose,&ping,&jwin);               /*自定义判断函数*/
		total=win+lose+ping;
		printf("\n");
		printf("            ------------------------------------------------------------\n");
		printf("            |                                                          |\n");
		printf("            |----玩家信息：赢%d局，输%d局，平%d局，净赢%d局,共玩%d局---|\n",win,lose,ping,jwin,total);
		printf("            |                                                          |\n");
		printf("            ---------------------------练习结束-------------------------\n");
	}
/*******************************实名对战模式(主函数)***********************************/
	else
	{
		printf("请输入玩家数量：\n");
		scanf("%d",&n);
		for(i=0;i<n;i++){
			printf("\n请输入第%d玩家名称：\n",i+1);
			u[i]=input_user();
			judge(&win,&lose,&ping,&jwin);
			u[i].win=win;u[i].lose=lose;u[i].ping=ping;u[i].jwin=jwin;            /*对结构体数组直接赋值*/ 
		}sort_user(u,n);                                                         /*排序：按净赢局数由大到小排名*/
		printf("\n"); 
		printf("\n----------------------------------玩家排行榜-----------------------------------\n");
		output_user(u,n);                                                         /*输出排序后的玩家信息记录*/ 
	}

}
/**********************************用户信息输入函数定义***********************************/
struct user input_user()
{
	struct user u;
	printf("姓名:");
	scanf("%s",&u.name);
	return u;
};
/**********************************判断输赢的函数定义**********************************/
void judge(int *pwin,int *plose,int *pping,int *pjwin)
{
	int lose=0,win=0,ping=0,jwin=0;
	int user,com;
	do{
		printf("请出拳(1.剪刀、2.石头、3.布):");
		scanf("%d",&user);
		srand((unsigned)time(NULL));
		com=rand()%3+1;
		printf("电脑出%s\n",com==1?"剪刀":com==2?"石头":"布");
		switch(com-user)
		{
			case 0:
			printf("--------平手----------------\n");ping=ping+1;
			break;
			case 1:
			case -2:
			printf("--------电脑赢了------------\n");lose=lose+1;
			break;
			case -1: 
			case 2:
			printf("--------你赢了--------------\n");win=win+1;
			break;
			default:printf("Error!!!\n");break;
		}
	} while(!(win==2||lose==2));
	jwin=win-lose;
	*pwin=win;*plose=lose;*pping=ping;*pjwin=jwin;
}
/********************************************排行榜函数（排序）********************************************/
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
/********************************************排行榜输出函数定义********************************************/
void output_user(struct user u[],int n)
{
	int i;
	printf("名称  赢局数  输局数  平局数  净赢局数\n");
	for(i=0;i<n;i++)
	{
		printf("%-10s%-3d%-3d%-3d%-3d\n",u[i].name,u[i].win,u[i].lose,u[i].ping,u[i].jwin);
	}
}

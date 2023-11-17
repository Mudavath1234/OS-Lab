#include<stdio.h>
#include<stdlib.h>
struct process
{
	int at,bt,ct,tat,wt,c;
};

int findprocess(struct process* p,int n,int t)
{
	int min=99999,index=-1;
	for(int i=0;i<n;i++)
	{
		if(p[i].at<=t && p[i].c==0)
		{
			if(p[i].bt<min)
			{
				min=p[i].bt;
				index=i;
			}
		}
	}
	return index;
}
	
int main()
{
	int n,t=0,ct=0,k=0, index,sum1=0,sum2=0;
	printf("Enter number of Processors :");
	scanf("%d",&n);
	struct process *p;
	p=(struct process*)malloc(n*sizeof(struct process));
	printf("Enter the Arrival & Burst Time Respectively :");
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].c=0;
	}
	
	while(k<n)
	{
		index=findprocess(p,n,t);
		if(index!=-1)
		{
			p[index].c=1;
			p[index].ct=ct+p[index].bt;
			p[index].tat=p[index].ct-p[index].at;
			p[index].wt=p[index].tat-p[index].bt;
			t=p[index].ct;
			ct=t;
			k=k+1;
		}
		else
		{
			t=t+1;
			ct=ct+1;
		}
	}
	printf("PNO\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	for(int i=0;i<n;i++)
	{
		sum1+=p[i].tat;
		sum2+=p[i].wt;
	}
	float f1,f2;
	f1=sum1/n;
	f2=sum2/n;
	printf("Average TAT is :%.2f\nAverage WT is :%.2f\n",f1,f2);
}
	
	
	
	

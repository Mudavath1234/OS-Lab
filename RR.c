#include<stdio.h>
int main()
{
	int n;
	printf("Enter No.of Processes: ");
	scanf("%d",&n);
	int n1=n;
	int at[n];
	int bt[n];
	int ct[n];
	int tot[n];
	int wt[n];
	int temp[n];
	int visited[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter Arrive Time: ");
		scanf("%d",&at[i]);
		printf("Enter Burst Time: ");
		scanf("%d",&bt[i]);
		temp[i]=bt[i];
		visited[i]=0;
		ct[i]=0;
		wt[i]=0;
		tot[i]=0;
	}
	int qtm;
	printf("Enter Quantum Time: ");
	scanf("%d",&qtm);
	int sm=0,i=0,wtt=0,tt=0;
	for(i=0;n>0;)
	{
		if(temp[i]<qtm && temp[i]>0)
		{
			sm+=temp[i];
			temp[i]=0;
		}
		if(temp[i]>=qtm)
		{
			temp[i]=temp[i]-qtm;
			sm+=qtm;
		}
		if(temp[i]==0 && visited[i]==0)
		{
			n-=1;
			visited[i]=1;
			ct[i]=sm;
			tot[i]=ct[i]-at[i];
			wt[i]=tot[i]-bt[i];
		}
		if(i==n1-1)
			i=0;
		else if(at[i+1]<=sm)
			i+=1;
		else
			i=0;
	}
	printf("At\tbt\tct\ttot\twt\n");
	float wait=0,turn=0;
	for(int i=0;i<n1;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d",at[i],bt[i],ct[i],tot[i],wt[i]);
		turn+=tot[i];
		wait+=wt[i];
		printf("\n");
	}
	printf("Avg Turn Around Time: %.2f\n",turn/n1);
	printf("Avg Waiting Time: %.2f\n",wait/n1);
} 

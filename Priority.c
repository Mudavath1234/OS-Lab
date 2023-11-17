#include<stdio.h>
int main()
{
	int n;
	printf("Enter No.of Operations: ");
	scanf("%d",&n);
	int prior[n];
	int at[n];
	int bt[n];
	int ct[n];
	int tot[n];
	int wt[n];
	int temp[n];
	int visited[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter Arrival Time: ");
		scanf("%d",&at[i]);
		printf("Enter Burst Time: ");
		scanf("%d",&bt[i]);
		printf("Enter Priority: ");
		scanf("%d",&prior[i]);
		visited[i]=0;
		temp[i]=bt[i];
		wt[i]=0;
		tot[i]=0;
		ct[i]=0;
	}
	int n1=n;
	temp[0]-=1;
	int sm=1;
	while(n>0)
	{
		int ind=-1;
		int dft=-1;
		for(int j=0;j<n1;j++)
		{
			if(at[j]<=sm && temp[j]>0 && visited[j]==0)
			{
				if(dft==-1)
				{
					dft=prior[j];
					ind=j;
				}
				else if(dft<prior[j])
				{
					dft=prior[j];
					ind=j;
				}
			}
		}
		if(ind!=-1)
		{
			if(temp[ind]>0)
			{
				temp[ind]-=1;
				sm+=1;
			}
			if(temp[ind]==0 && visited[ind]==0)
			{
				n-=1;
				visited[ind]=1;
				ct[ind]=sm;
				tot[ind]=sm-at[ind];
				wt[ind]=sm-at[ind]-bt[ind];
			}
		}
		//printf("n-->%d\n",n);
	}
	printf("AT\tBT\tPrior\tCT\tTOT\tWT\tvisi\n");
	for(int i=0;i<n1;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",at[i],bt[i],prior[i],ct[i],tot[i],wt[i],visited[i]);
	}
}

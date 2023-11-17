#include<stdio.h>
#include<limits.h>
struct point 
{
	int id;
	int size;
	int blk;
};
int main()
{
	int n1,n2;
	printf("Enter Size of Free Blocks: ");
	scanf("%d",&n1);
	int visited[n1];
	printf("Enter Size of Jobs: ");
	scanf("%d",&n2);
	struct point process[n2];
	printf("Enter Id___size of Jobs\n");
	for(int i=0;i<n2;i++)
	{
		scanf("%d %d",&process[i].id,&process[i].size);
		process[i].blk=0;
	}
	int blocks[n1];
	printf("Enter Size of free blocks: ");
	for(int i=0;i<n1;i++)
	{
		scanf("%d",&blocks[i]);
		visited[i]=0;
	}
	for(int i=0;i<n2;i++)
	{
		int index=-1;
		int min=INT_MIN;
		for(int j=0;j<n1;j++)
		{
			if(visited[j]==0 && min<=blocks[j] &&blocks[j]>=process[i].size)
			{	
				index=j;
				min=blocks[j];
			}                                                                     
		}
		if(index!=-1)
		{
			process[i].blk=blocks[index];
			visited[index]=1;
		}
	}
	printf("Id\tSize\tBlock\n");
	for(int i=0;i<n2;i++)
	{
		printf("%d\t%d\t%d\n",process[i].id,process[i].size,process[i].blk);
	}
}

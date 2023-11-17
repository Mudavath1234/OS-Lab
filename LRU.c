#include<stdio.h>
#include<limits.h>
struct node
{
	int val;
	int stamp;
};
int find_min_index(struct node frame[],int size)
{
	int min=INT_MAX;
	int index=-1;
	for(int i=0;i<size;i++)
	{
		if(min>frame[i].stamp)
		{
			min=frame[i].stamp;
			index=i;
		}
	}
	return index;
}
int main()
{
	int n;
	printf("Enter Length of String: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter String: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int m;
	int sl=0;
	int time=1;
	printf("Enter Frame Size: ");
	scanf("%d",&m);
	struct node frame[m];
	for(int i=0;i<m;i++)
	{
		frame[i].val=-1;
		frame[i].stamp=0;
	}
	int frame_count=0;
	for(int i=0;i<n;i++)
	{
		if(sl<m)
		{
			frame[sl].val=arr[i];
			frame[sl].stamp=time;
			sl+=1;
			frame_count+=1;
		}
		else
		{
			int flag=0;
			for(int j=0;j<m;j++)
			{
				if(frame[j].val==arr[i])
				{	
					flag=1;
					frame[j].stamp=time;
					break;
				}
			}
			if(flag==0)
			{
				printf("MISS\n");
				int index=find_min_index(frame,m);
				frame[index].stamp=time;
				frame[index].val=arr[i];
				frame_count+=1;
			}
			if(flag==1)
				printf("HIT\n");
		}
		time+=1;
		for(int j=0;j<m;j++)
		{
			printf("%d\t",frame[j].val);
		}
		printf("\n");
	}
	printf("Frame Count: %d",frame_count);
}

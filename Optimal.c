#include<stdio.h>
#include<limits.h>
struct node
{
	int val;
	int stamp;
};
int check(int temp[],struct node frame[],int index,int arr[],int m,int n)
{
	int time=1;
	for(int i=index+1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(frame[j].val==arr[i])
			{
				if(temp[j]==-1)
				{
					temp[j]=time;
				}				
			}
		}
		time+=1;
	}
}
int main()
{
	int n;
	printf("Enter Length of String: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter String: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int m;
	printf("Enter Length of Frame: ");
	scanf("%d",&m);
	struct node frame[m];
	for(int j=0;j<m;j++)
	{
		frame[j].val=-1;
		frame[j].stamp=0;
	}
	int sl=0;
	int time=1;
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
					frame[j].stamp=time;
					flag=1;
					break;
				}
			}
			if(flag==1)
				printf("HIT\n");
			if(flag==0)
			{
				int temp[m];
				for(int j=0;j<m;j++)
					temp[j]=-1;
				check(temp,frame,i,arr,m,n);
				int index_nega=-1;
				int min_nega=INT_MAX;
				int min=0;
				int index=-1;
				for(int j=0;j<m;j++)
				{
					if(temp[j]==-1)
					{
						if(min_nega>frame[j].stamp)
						{
							min_nega=frame[j].stamp;
							index_nega=j;
						}
					}
					else
					{
						if(min<temp[j])
						{
							min=temp[j];
							index=j;
						}
					}
				}
				if(index_nega!=-1)
				{
					frame[index_nega].val=arr[i];
					frame[index_nega].stamp=time;
					frame_count+=1;
				}
				else
				{
					frame[index].val=arr[i];
					frame[index].stamp=time;
					frame_count+=1;
				}
				printf("MISS\n");
			}
			
		}
		for(int j=0;j<m;j++)
			printf("%d\t",frame[j].val);
		printf("\n");
		time+=1;
	}
	printf("Frame_count: %d",frame_count);
	
}

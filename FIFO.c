#include<stdio.h>
int main()
{
	int n;
	printf("Enter Length of String: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter String: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int ptr=0;
	int sl=0;
	int m;
	printf("Enter Frame Size: ");
	scanf("%d",&m);
	int frame[m];
	for(int i=0;i<m;i++)
		frame[i]=-1;
	int frame_count=0;
	for(int i=0;i<n;i++)
	{
		if(sl<m)
		{	
			frame[sl]=arr[i];
			sl+=1;
			frame_count+=1;
		}
		else
		{
			int flag=0;
			for(int j=0;j<m;j++)
			{
				if(frame[j]==arr[i])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				frame[ptr]=arr[i];
				ptr=(ptr+1)%m;
			}
			if(flag==1)
				printf("HIT\n");
			else if(flag==0)
			{
				frame_count+=1;
				printf("MISS\n");
			}
		}
		for(int j=0;j<m;j++)
			printf("%d\t",frame[j]);
		printf("\n");
	}	
	printf("No.of Frames: %d",frame_count);
}

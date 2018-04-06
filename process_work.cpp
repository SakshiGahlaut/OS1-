#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<malloc.h>
void readyQueue(int b,int c);
void status(int a);
void sjf(int w);
void execute(int y);
void scheduler(int a);
void sort(int e);
static int count1=0,count2;
struct pro {
	int burst ;
	int arrival;
	int id;

}z[100];
struct ReadyQueue{
	int burst;
	int flag=0;
	int id;
}d[100];
int x=0;
void scheduler(int a)
{
	int i,z;
	z=0;
	for(i=0;i<20;i++)
	{
		readyQueue(i,a);
		if(d[z].burst!=0 && z<=a )				
		{
			d[z].burst=d[z].burst-1;
			count1=count1+1;
		}
		if(x!=0 && (count1%3==0) && count2!=count1)
		{
			z++;
			count2=count1;
		}
		if(i==19)
		{
			printf("\nFIRST ITERATION (three seconds)\n "); //TIMED OUT AFTER EXECUTION FOR 3 SECONDS
			status(a);
			execute(a);
		}
	}	
}

void readyQueue(int b,int c)
{
	int i;
	for(i=0;i<c;i++)
	{
		if(z[i].arrival==b )
		{
			d[x].burst=z[i].burst;
			d[x].id=z[i].id;
			x=x+1;
		}
	}	
}
void execute(int y)
{
	int i;
	int j;
	for(i=0;i<y;i++)
	{
		for(j=0;j<6;j++) 
		{
			if(d[i].burst==0)
			{goto out;
			}
			else
			{
					d[i].burst=d[i].burst-1;
			}
		
		}
			out:{}
	}
	printf("\nSECOND ITERATION(six seconds) \n"); //Timed out after execution for six seconds
	status(y);
	sort(y);
}

void sort(int e)
{
   int i, j,temp,temp1,temp2;
   for (i = 0; i < e-1; i++)      
    {    
       for (j = 0; j < e-i-1; j++) 
       {
           if (d[j].burst > d[j+1].burst)
           {
              temp=d[j].burst;
              temp1=d[j].id;
              temp2=d[j].flag;
             
              d[j].burst=d[j+1].burst;
              d[j].id=d[j+1].id;
              d[j].flag=d[j+1].flag;
              d[j+1].burst=temp;
              d[j+1].id=temp1;
              d[j+1].flag=temp2;
        	}
        }
    }
	sjf(e);
}

void sjf(int w)
{int a,i;
		printf("\nTHIRD ITERATION ACCORDING TO SJF \n");//shortest job first
	for(i=0;i<w;i++)
	{
		if(d[i].burst!=0)
		{
			a=d[i].burst;
			d[i].burst=d[i].burst-a;
			printf("\n Process P%d complete ",d[i].id);			
		}
		else if(d[i].burst==0 && d[i].flag ==0)
		{
			printf("\n Process P%d complete",d[i].id);
		
		}
		
	}
}
void status(int a)
{
	int i;
	for(i=0;i<a;i++)
	{
		if(d[i].burst==0 && d[i].flag==0)
		{
			printf("\n Process P%d complete",d[i].id);
			d[i].flag=1;
		}
		else if(d[i].burst!=0)
		{
			printf("\n Process P%d is in progress : %d",d[i].id,d[i].burst);
		}
	}
}
int main()
{	int i;
	for(i=0;i<4;i++)//there are four processes according to question
	{

		printf("\nEnter burst time of process %d : " , i+1);
		scanf("%d" , &z[i].burst);
		printf("Enter the arrival time of process : ",i+1);
		scanf("%d" , &z[i].arrival);
		z[i].id=i+1;
		
	}
	scheduler(4);
		
	
}



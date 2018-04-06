#include <stdio.h>
#include <stdlib.h>
int main()
{
    int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
    int i, j, process, count;
    count = 0;
	printf("No. of processes : 5 ");
    for(i = 0; i< 5; i++)
        completed[i] = 0;
    printf("\n No of resources : 4 ");
    Max[0][0]=0;
    Max[0][1]=0;
    Max[0][2]=1;
    Max[0][3]=2;
    Max[1][0]=1;
    Max[1][1]=7;
    Max[1][2]=5;
    Max[1][3]=0;
    Max[2][0]=2;
    Max[2][1]=3;
    Max[2][2]=5;
    Max[2][3]=6;
    Max[3][0]=0;
    Max[3][1]=6;
    Max[3][2]=5;
    Max[3][3]=2;
    Max[4][0]=0;
    Max[4][1]=6;
    Max[4][2]=5;
    Max[4][3]=6;
    for(i=0;i<5;i++)
    {
    	printf("\nfor process P%d the Max matrix for each resource is :   ",i);
    	for(j=0;j<4;j++)
    	{
    		printf("  %d,",Max[i][j]);
    	}
    }
    alloc[0][0]=0;
    alloc[0][1]=0;
    alloc[0][2]=1;
    alloc[0][3]=2;
    alloc[1][0]=1;
    alloc[1][1]=0;
    alloc[1][2]=0;
    alloc[1][3]=0;
    alloc[2][0]=1;
    alloc[2][1]=3;
    alloc[2][2]=5;
    alloc[2][3]=4;
    alloc[3][0]=0;
    alloc[3][1]=6;
    alloc[3][2]=3;
    alloc[3][3]=2;
    alloc[4][0]=0;
    alloc[4][1]=0;
    alloc[4][2]=1;
    alloc[4][3]=4;
    for(i=0;i<5;i++)
    {
    	printf("\nfor process P%d the Allocation matrix for each resource is:    ",i);
    	
    	for(j=0;j<4;j++)
    	{
    		printf("  %d,",alloc[i][j]);
    	}
    }
    printf("\n\Available Resources : ");
    avail[0]=1;
    avail[1]=5;
	avail[2]=2;
	avail[3]=0;
	for(i=0;i<4;i++)
	{
		printf("  %d,",avail[i]);
	}
	    for(i = 0; i < 5; i++)
        for(j = 0; j < 4; j++)
            need[i][j] = Max[i][j] - alloc[i][j];
        do
        {
            printf("\n Max matrix:\tAllocation matrix:\n");
            for(i = 0; i < 5; i++)
            {
                for( j = 0; j < 4; j++)
                    printf("%d ", Max[i][j]);
                printf("\t\t");
                for( j = 0; j < 4; j++)
                    printf("%d ", alloc[i][j]);
                printf("\n");
            }
            process = -1;
            for(i = 0; i < 5; i++)
            {
                if(completed[i] == 0)
                {
                    process = i ;
                    for(j = 0; j < 4; j++)
                    {
                        if(avail[j] < need[i][j])
                        {
                            process = -1;
                            break;
                        }
                    }
                }
                if(process != -1)
                    break;
            }
            if(process != -1)
            {
                printf("\nProcess P%d completes", process );
                safeSequence[count] = process ;
                count++;
                for(j = 0; j < 4; j++)
                {
                    avail[j] += alloc[process][j];
                    alloc[process][j] = 0;
                    Max[process][j] = 0;
                    completed[process] = 1;
                }
            }
        }
        while(count != 5 && process != -1);
        if(count == 5)
        {
            printf("\nSystem is in safe state");
            printf("\nSafe Sequence : < ");
            for( i = 0; i < 5; i++)
                printf("P%d ", safeSequence[i]);
            printf(">\n");
        }
        else
            printf("\nSystem is in unsafe state");
}

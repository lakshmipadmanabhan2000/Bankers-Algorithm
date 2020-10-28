#include<stdio.h>
void main(){
    int available[100],max[20][100],need[20][100],allocation[20][100],flag,finish[20];
    int i,np,nr,j,safe[20],k=0;
    printf("Enter number of processes: ");
    scanf("%d",&np);
    printf("Enter number of resources: ");
    scanf("%d",&nr);
    printf("Enter availability of instances of each resource: ");
    for(i=0;i<nr;i++){
        scanf("%d",&available[i]);
    }
    safe[np];
    printf("Enter maximum number of instances of each resource required by each process");
    printf("\nEnter max matrix :\n");
    for ( i = 0; i < np; i++)
    {
        for(j=0;j<nr;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter maximum number of instances of each resource requestes by each process");
    printf("\nEnter allocation matrix :\n");
    for ( i = 0; i < np; i++)
    {
        for(j=0;j<nr;j++)
        {
           scanf("%d",&allocation[i][j]);
        }
    }
    //compute need matrix
    for ( i = 0; i < np; i++)
    {
        for(j=0;j<nr;j++)
        {
           need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    //display all matrices-allocation need and max
     printf("Max matrix:\n");
    for ( i = 0; i < np; i++)
    {
        for(j=0;j<nr;j++)
        {
           printf("%d ",max[i][j]);
        }
        printf("\n");
    }
    printf("Allocation matrix:\n");
    for ( i = 0; i < np; i++)
    {
        for(j=0;j<nr;j++)
        {
           printf("%d ",allocation[i][j]);
        }
        printf("\n");
    }
    printf("Need matrix:\n");
    for ( i = 0; i < np; i++)
    {
        for(j=0;j<nr;j++)
        {
           printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    for ( i = 0; i < np; i++)
    {
        finish[i]=0;
    }
     for (int x = 0; x < np; x++)
     {
         /* code */
      
    for ( i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            if(finish[i]==0)
            {
                if (need[i][j]<=available[j])
                {
                    flag=0;
                }  
                else{
                    flag=1;
                    break;
                }
            }
            else
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            finish[i]=1;
            safe[k++]=i;
            for(j=0;j<nr;j++){
                available[j]+=allocation[i][j];
            }
        }
    }
    }
    if(k==np){
    printf("Safe Sequence is:\n");
    for ( i = 0; i < np-1; i++)
    {
        printf("P%d -> ",safe[i]);
        
    }
    printf("P%d\n",safe[i]);
    }
    else
    {
        printf("Not in safe state");
    }
    
}
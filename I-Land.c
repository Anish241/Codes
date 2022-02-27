#include<stdio.h>
void row_traverser(int arr[100][100],int*points,int n)
{
    for(int i=0;i<2*n;i=i+2)
    {   
        int row=points[i];
        
        for(int j=points[i+1]+1;j<100;j++)
        {   
            if(arr[row][j]==1)
            {
                for(int k=points[i+1];k<j;k++)
                {
                    arr[row][k]=2;
                }
            }
        }
    }
}

void column_traverser(int arr[100][100],int*points,int n)
{
    for(int i=0;i<2*n;i=i+2)
    {
       int col=points[i+1];

       for(int j=points[i];j<100;j++)
       {
           if(arr[j][col]==1)
           {
               for(int k=points[i];k<j;k++)
               {
                   arr[k][col]=2;
               }
           }
       }
       
    }
}

void cross_traverser(int arr[100][100],int*points,int n)
{   
    for(int i=0;i<2*n;i=i+2)
    {
        int row=points[i];
        int col=points[i+1];

        while(row>=0 && col>=0)
        {
            if(arr[row][col]==1 || arr[row][col]==2)
            {
                int tempr=points[i];
                int tempc=points[i+1];
                while(tempr>=0 && tempc>=0)
                {
                     arr[tempr][tempc]=2;
                      tempr--;
                      tempc--;
                }
            }
            row--;
            col--; 

        }
    }
    
    for(int i=0;i<2*n;i=i+2)
    {
        int row=points[i];
        int col=points[i+1];

        while(row<100 && col<100)
        {
            if(arr[row][col]==1 || arr[row][col]==2)
            {
                int tempr=points[i];
                int tempc=points[i+1];

                while(tempr<100 && tempc<100)
                {
                     arr[tempr][tempc]=2;
                      tempr++;
                      tempc++;
                }
            }

            row++;
            col++; 
        }
    }

    for(int i=0;i<2*n;i=i+2)
    {
        int row=points[i];
        int col=points[i+1];

        while(row>=0 && col<100)
        {
             if(arr[row][col]==1 || arr[row][col]==2)
             {
                 int tempr=points[i];
                int tempc=points[i+1];
                while(tempr>=0 && tempc<100)
                  {
                      arr[tempr][tempc]=2;
                      tempr--;
                      tempc++;
                  }
             }
            row--;
            col++; 

        }
    }


    for(int i=0;i<2*n;i=i+2)
    {
         int row=points[i];
         int col=points[i+1];

         while(row>=0 && col<100)
         {
             if(arr[row][col]==1 || arr[row][col]==2)
             {
                 int tempr=points[i];
                  int tempc=points[i+1];

                  while(tempr>=0 && tempc<100)
                  {
                      arr[tempr][tempc]=2;
                      tempr--;
                      tempc++;
                  }
             }
            row--;
            col++; 
         }

    }

     for(int i=0;i<2*n;i=i+2)
     {
         int row=points[i];
         int col=points[i+1];

          while(row<100 && col>=0)
          {
              if(arr[row][col]==1 || arr[row][col]==2)
              {
                  int tempr=points[i];
                  int tempc=points[i+1];

                  while(tempr>=0 && tempc<100)
                  {
                      arr[tempr][tempc]=2;
                      tempr++;
                      tempc--;
                  }
              }
            row++;
            col--; 
          }
     }

}

void marker(int arr[100][100],int*points,int n)
{
    for(int i=0;i<2*n;i=i+2)
    {
        arr[points[i]][points[i+1]]=1;
    }
}

int checker(int arr[100][100],int i,int j)
{
    if(arr[i][j]==0)
    {
        return 0;
    }

    else if(arr[i][j]==2)
    {
        return 2;
    }

    else
    {
        return 1;
    }
}


int main()
{
    int arr[100][100]={0},n,x,y;
    printf("Enter the number of vertices: \n");
    scanf("%d",&n);
    int points[2*n];
    printf("Enter the points of vertices as row and column consecuitively: \n");
    for(int i=0;i<2*n;i++)
    {
        if(i%2==0)
        {
            printf("Enter the x-coordinate: \n");
            scanf("%d",&points[i]);
        }

        else
        {
            printf("Enter the y-coordinate: \n");
            scanf("%d",&points[i]);
        }
    }
    
    
    marker(arr,points,n);
    row_traverser(arr,points,n);
    column_traverser(arr,points,n);
    cross_traverser(arr,points,n);

    printf("Enter the point you have to check: \n");

    printf("Enter the x - co-ordinate: \n");
    scanf("%d",&x);
     printf("Enter the y - co-ordinate: \n");
    scanf("%d",&y);

    int result= checker(arr,x,y);

    if(result==0)
    {
        printf("The point is in the sea.");

    }

    else if(result==2)
    {
        printf("The point is on island.");
    }
    
    else
    {
        printf("The point is on vertex.");
    }
    


    



  return 0;
}
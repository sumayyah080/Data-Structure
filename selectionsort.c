
#include<stdio.h>
void selectionSort(int a[],int n)
{
    int temp;
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for( int j=i+1; j<n; j++)
        {
            if(a[j]< a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
               temp = a[i];
                a[i]=a[min];
                a[min]=temp;

        }

    }
    printf("Sorted Array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    int a[100],n;
    printf("Enter number of Elements: ");
    scanf("%d",&n);
    printf("Enter %d Elements: ",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    selectionSort(a,n);
    return 0;
}

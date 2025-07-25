#include<stdio.h>
void bubbleSort(int a[],int n)
{
    int temp;
    for(int i=0; i<n-1; i++)
    {
        int swapped=0;
        for( int j=0; j<n-1-i; j++)
        {
            if(a[j]> a[j+1])
            {
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                swapped=1;
            }
        }
        if(swapped==0)
           break;
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
    bubbleSort(a,n);
    return 0;
}

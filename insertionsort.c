#include<stdio.h>
void insertionSort(int a[],int n)
{

    for(int i=1; i<n; i++)
    {
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
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
    insertionSort(a,n);
    return 0;
}




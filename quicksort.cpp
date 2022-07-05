# include<iostream>
using namespace std;
int part(int *a,int low,int high)
{
    int i=low;
    int j=high+1;
    int pivot=a[low];
    while(i<j)
    {
        do
        {
            i++;
        }while(a[i]<=pivot);
        do
        {
            j--;
        }while(a[j]>pivot);
        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        
    }
    int temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}
void sort(int *a,int low,int high)
{
    if(low>high)
    return ;
    int k=part(a,low,high);
    sort(a,low,k-1);
    sort(a,k+1,high);
}
int main()
{
    int n;
    cout<<"Enter the number of elements:-\n";
    cin>>n;
    int *a=new int [n];
    cout<<"Enter the array elements:-\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,0,n-1);
    cout<<"Array elements after sorting is:-\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

    return 0;
}

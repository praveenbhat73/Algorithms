# include<iostream>
using namespace std;
void merge_sort(int *a,int low,int high,int mid)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int l[n1],r[n2];
    for(int i=0;i<n1;i++)
    l[i]=a[low+i];
    for(int j=0;j<n2;j++)
    r[j]=a[mid+1+j];
    int i=0,j=0,k=low;
    while(i<n1&&j<n2)
    {
        if(l[i]<=r[j])
        a[k++]=l[i++];
        else
        a[k++]=r[j++];
    }
    while(i<n1)
    a[k++]=l[i++];
    while(j<n2)
    a[k++]=r[j++];
}
void sort(int *a,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        sort(a,low,mid);
        sort(a,mid+1,high);
        merge_sort(a,low,high,mid);
    }
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

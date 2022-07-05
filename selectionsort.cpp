# include<iostream>
using namespace std;
void selection_sort(int *a,int n)
{
    int i,j;
    int pos;
    for(i=0;i<n-1;i++)
    {
       pos=i;
       for(j=i+1;j<n;j++)
        {
            if(a[j]<a[pos])
            pos=j;
        }
        int temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
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
    selection_sort(a,n);
    cout<<"Array elements after sorting is:-\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

    return 0;
}

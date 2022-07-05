# include<iostream>
using namespace std;
void insertion_sort(int *a,int n)
{
    int i,j;
    int x;
    for(i=1;i<n;i++)
    {
        j=i-1;
        x=a[i];
        while(j>=0&&a[j]>x)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
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
    insertion_sort(a,n);
    cout<<"Array elements after sorting is:-\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

    return 0;
}

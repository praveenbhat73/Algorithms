# include<iostream>

using namespace std;
int main()
{
    int i,j,k;
    int n;
    cout<<"Enter the number of array elements:-\n";
    cin>>n;
    int  a[n][n];
    cout<<"Enter the matrix:\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]<a[i][k]+a[k][j])
                a[i][j]=a[i][j];
                else
                a[i][j]=a[i][k]+a[k][j];
            }
        }
    }
    cout<<"Resultant Matrix by Floyd's algorithm:-\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
# include<iostream>
# include<string>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    int m;
    cout<<"Enter the number m\n";
    cin>>m;
    int a[n+1][m+1];
    int i,j;
   
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            a[i][j]=0;
        }
    }
    for(i=0;i<=n;i++){
    a[i][0]=1;
    a[i][i]=1;
    }
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            a[i][j]=a[i-1][j]+a[i-1][j-1];
        }
    }
    cout<<"Table\n";
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
   
    cout<<"Answer is:- "<<a[n][m];
    return 0;
}
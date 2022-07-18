# include<iostream>
# include<string>
using namespace std;
int max(int a,int b)
{
    if(a>=b)return a;
    else return b;
}
int main()
{
    int n;
    cout<<"Enter the number of items\n";
    cin>>n;
    int m;
    cout<<"Enter the number of capacity\n";
    cin>>m;
    int a[n+1][m+1];
    int i,j;
    int p[n+1],w[n+1];
    cout<<"Enter weights\n";
    for(i=1;i<=n;i++)
    cin>>w[i];
    cout<<"Enter profits\n";
    for(i=1;i<=n;i++)
    cin>>p[i];
    for(i=0;i<=n;i++)
    a[i][0]=0;
    for(j=0;j<=m;j++)
    a[0][j]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(j<w[i])
            {
                a[i][j]=a[i-1][j];
            }
            else
            a[i][j]=max(a[i-1][j],p[i]+a[i-1][j-w[i]]);
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
    int x[n];
    for(int i=1;i<=n;i++)
    x[i]=0;
    i=n;
    j=m;
    while(i!=0&&j!=0)
    {
        if(a[i][j]!=a[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }
    cout<<"ITEMS SELECTED\n";
    for(i=1;i<=n;i++)
    cout<<x[i]<<" ";
    cout<<endl;
    return 0;
}
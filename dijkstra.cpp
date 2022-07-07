#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of vertices:\n";
    cin>>n;
    int a[n][n];
    int i,j;
    cout<<"Enter the cost adjacency matrix:-\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int d[n],s[n];
    int src;
    cout<<"Enter the source\n";
    cin>>src;
    for(i=0;i<n;i++)
    {
        d[i]=a[src][i];
        s[i]=0;
        
    }
    cout<<"Intial distance from source is:- ";
    for(i=0;i<n;i++)
    cout<<d[i]<<" ";
    cout<<endl;
    s[src]=1;
    int u=src;
    for(i=0;i<n;i++)
    {
        int m=999;
        for(j=0;j<n;j++)
        {
            if(d[j]<m&&s[j]==0)
            {
                m=d[j];
                u=j;
            }
        }
        s[u]=1;
        for(int v=0;v<n;v++)
        {
            if(s[v]==0)
            {
                if(d[u]+a[u][v]<d[v])
                d[v]=d[u]+a[u][v];
            }
        }
    }
    cout<<"Final distance vector is after dijkstra algorithm is applied:\n";
    for(i=0;i<n;i++)
    cout<<d[i]<<" ";
    return 0;
}
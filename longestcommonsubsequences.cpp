# include<iostream>
# include<string>
using namespace std;
void lcs(string s1,string s2)
{
    int i,j;
    int n=s1.length();
    int m=s2.length();
    int l[n+1][m+1];
    for(i=0;i<=n;i++)
    l[i][0]=0;
    for(j=0;j<=m;j++)
    l[0][j]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(s1[i]==s2[j])
            {
                l[i][j]=1+l[i-1][j-1];
            }
            else if(l[i-1][j]>=l[i][j-1])
            l[i][j]=l[i-1][j];
            else
            l[i][j]=l[i][j-1];
        }
    }
    cout<<"TABLE :-\n";
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Maximum common subsequences is:- "<<l[n][m];
    int x=l[n][m];
    char index[x];
    i=n;
    j=m;
    while(i>=0&&j>=0)
    {
        if(s1[i]==s2[j])
        {
            index[x--]=s1[i];
            i--;
            j--;
        }
        else if(l[i-1][j]>=l[i][j-1])
        i--;
        else
        j--;
    }
    
    cout<<"\nThe longest common subsequences is :- "<<index<<" ";
    
    
    
}
int main()
{
    string s1,s2;
    cout<<"Enter the first string:-\n";
    cin>>s1;
    cout<<"Enter the Second string:-\n";
    cin>>s2;
    lcs(s1,s2);
    return 0;
}
// RANK SORT USING C++:-
# include<iostream>
using namespace std;
int *rank_sort(int *a,int n)
{
  int i,j;
  int *b=new int[n];
  int r[n];
  for(i=0;i<n;i++)
    r[i]=0;
  for(i=1;i<n;i++)
  {
    for(j=i-1;j>=0;j--)
    {
      if(a[i]>=a[j])
        r[i]++;
      else
        r[j]++;
    }
  }
  for(i=0;i<n;i++)
    b[r[i]]=a[i];
  return b;
}
int main()
{
  int n,i;
  cout<<"Enter the size of the array:-\n";
  cin>>n;
  int *a=new int[n];
  cout<<"Enter the array elements:-\n";
  for(i=0;i<n;i++)
    cin>>a[i];
  int *b=rank_sort(a,n);
  cout<<"Array elements after sorting :-\n";
  for(i=0;i<n;i++)
    cout<<b[i]<<" ";
  return 0;
}

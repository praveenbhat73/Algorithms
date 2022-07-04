//Travelling salesperson problem code 

#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int arr[10][10], n, visit[10];
int cost_opt = 0, cost_apr = 0;
int least_apr(int c);
int least_opt(int c);

void mincost(int city){
    int i, ncity;
    visit[city] = 1;
    cout<<"--> "<<city<<endl;
    ncity = least_opt(city);
    if (ncity == 999){
        ncity = 1;
        // cout<<" "<<ncity;
        cost_opt += arr[city][ncity];
        return;
    }
    mincost(ncity);
}
void mincost_apr(int city){
    int i, ncity;
    visit[city] = 1;
    cout<<"-->"<<city;
    ncity = least_apr(city);
    if (ncity == 999){
        ncity = 1;
        // cout<<""<<ncity;
        cost_apr += arr[city][ncity];
        return;
    }
    mincost_apr(ncity);
}

int least_opt(int c){
    int i, nc = 999;
    int min = 999, kmin = 999;
    for (i = 1; i <= n; i++){
        if ((arr[c][i] != 0) && (visit[i] == 0))
            if (arr[c][i] < min){
                min = arr[i][1] + arr[c][i];
                kmin = arr[c][i];
                nc = i;
            }
    }
    if (min != 999)
        cost_opt += kmin;
    return nc;
}

int least_apr(int c){
    int i, nc = 999;
    int min = 999, kmin = 999;
    for (i = 1; i <= n; i++){
        if ((arr[c][i] != 0) && (visit[i] == 0))
            if (arr[c][i] < kmin){
                min = arr[i][1] + arr[c][i];
                kmin = arr[c][i];
                nc = i;
            }
        }
    if (min != 999)
        cost_apr += kmin;
    return nc;
}
int  main()
{
    int i, j;
    cout<<"Enter No. of cities: "<<endl;
    cin>>n;
    cout<<"Enter the cost matrix"<<endl;
    for (i = 1; i <= n; i++){
        
        for (j = 1; j <= n; j++)
            cin>>arr[i][j];
        visit[i] = 0;
    }
    
    
    cout<<"Optimal Solution:-"<<endl;
    cout<<"The path is :-"<<endl;
    mincost(1);
    cout<<"\nMinimum cost is :-"<<endl;
    cout<<cost_opt<<endl;
    cout<<"\nApproximated Solution:-"<<endl;
    for (i = 1; i <= n; i++)
        visit[i] = 0;
    cout<<"\nThe path is :-\n";
    mincost_apr(1);
    cout<<"\nMinimum cost :-\n"<<cost_apr<<endl;
    cout<<"\nError in approximation is approximated solution / optimal solution:-\n"<<((float)cost_apr / cost_opt)<<endl;
    return 0;
}
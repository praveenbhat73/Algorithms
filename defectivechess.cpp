#include<iostream>
using namespace std;

int tile=1;
int board[256][256];
void broken(int trow,int tcol,int drow,int dcol,int size){
  if(size>1){
    int qsize=size/2;
    int tiling=tile++;
    
    if(drow<=trow+qsize-1&&dcol<=tcol+qsize-1)
      broken(trow,tcol,drow,dcol,qsize);
    else{
      board[trow+qsize-1][tcol+qsize-1]=tiling;
      broken(trow,tcol,trow+qsize-1,tcol+qsize-1,qsize);
    }
    
    if(drow<=trow+qsize-1&&dcol>=tcol+qsize)
      broken(trow,tcol+qsize,drow,dcol,qsize);
    else{
      board[trow+qsize-1][tcol+qsize]=tiling;
      broken(trow,tcol+qsize,trow+qsize-1,tcol+qsize,qsize);
    }
    
    if(drow>=trow+qsize&&dcol<=tcol+qsize-1)
      broken(trow+qsize,tcol,drow,dcol,qsize);
    else{
      board[trow+qsize][tcol+qsize-1]=tiling;
      broken(trow+qsize,tcol,trow+qsize,tcol+qsize-1,qsize);
    }
    
    if(drow>=trow+qsize&&dcol>=tcol+qsize)
      broken(trow+qsize,tcol+qsize,drow,dcol,qsize);
    else{
      board[trow+qsize][tcol+qsize]=tiling;
      broken(trow+qsize,tcol+qsize,trow+qsize,tcol+qsize,qsize);
    }
  }
}

int main(){
  int n;
  cout<<"Enter the size of board : ";
  cin>>n;
  int dr,dc;
  cout<<"Enter the defective row and column number : ";
  cin>>dr>>dc;
  
  broken(0,0,dr,dc,n);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
 int H,W,h,w;
  cin>>H>>W>>h>>w;
  if(H%h==0 && W%w==0)
    cout<<"No"<<endl;
  else{
  cout<<"Yes"<<endl;
    vector<vector<int>>A(H,vector<int>(W));
    for(int i=0;i<H;i++)
      for(int j=0;j<W;j++)
        if(i%h==h-1 && j%w==w-1)
          A[i][j]=-4000*(h*w-1)-1;
    else
      A[i][j]=4000;
   for(int i=0;i<H;i++){
    for(int j=0;j<W-1;j++)
      cout<<A[i][j]<<" ";
    cout<<A[i][W-1]<<endl;
   }
  }
  return 0;
}

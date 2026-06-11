#include <bits/stdc++.h>
using namespace std;
long long a(vector<long long> A){
  return max({A[0],A[1],A[2]})-min({A[0],A[1],A[2]});
}
int main(){
  long long H,W;
  cin>>H>>W;
  if(H%3==0 || W%3==0)
    cout<<0<<endl;
  else{
    long long i=100000000;
    for(int j=0;j<2;j++){
      i=min(i,a({(W/3+1)*H,(W-W/3-1)*(H/2),(W-W/3-1)*((H+1)/2)}));
      swap(W,H);
    }for(int j=0;j<2;j++){
      i=min(i,a({(W/3)*H,(W-W/3)*(H/2),(W-W/3)*((H+1)/2)}));
      swap(W,H);
    }
    cout<<min({i,H,W})<<endl;
  }
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,A,B;
  cin>>N>>A>>B;
  vector<int> C(N);
  for(int &i:C)cin>>i;
  int ok=1000000000,ng=0;
  while(ok-ng>1){
    int n=(ok+ng)/2,cnt=0;
    for(int i=0;i<N;i++)cnt+=(max(C[i]-n*B,0LL)+A-B-1)/(A-B);
    if(n>=cnt)ok=n;
    else ng=n;
  }
  cout<<ok<<endl;
}
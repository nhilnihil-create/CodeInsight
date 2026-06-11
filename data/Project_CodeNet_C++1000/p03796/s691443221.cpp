#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=1;i<=N;i++)

signed main(){
  int X,N=1;
  cin>>X;
  rep(i,X){
    N*=i;
    if(N>1000000000)N%=1000000000+7;
  }
  cout<<N<<endl;
  return 0;
}
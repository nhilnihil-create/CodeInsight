#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,ans=0,i=0;
  cin>>N;
  while(pow(2,i)<=N){
    ans=i;
    i++;
  }
  cout<<pow(2,ans)<<endl;
  return 0;
}
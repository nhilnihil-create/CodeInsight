#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string N;
  cin>>N;
  string S=N;
  reverse(begin(S),end(S));
  if(S==N)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
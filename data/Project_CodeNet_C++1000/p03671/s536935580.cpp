#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  vector<int> R(3);
  rep(i,3)cin>>R[i];
  sort(begin(R),end(R));
  cout<<R[0]+R[1]<<endl;
  return 0;
}
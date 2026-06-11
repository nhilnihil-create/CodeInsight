#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string S;
  cin>>S;
  int SS=S.size();
  cout<<S[0]<<(SS-2)<<S[SS-1]<<endl;
  return 0;
}
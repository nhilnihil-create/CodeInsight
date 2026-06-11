#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n,c,k;
  cin>>n>>c>>k;
  vector<pair<int,int>> t(n);
  rep(i,n){
    int T;
    cin>>T;
    t[i]=make_pair(T,T+k);
  }
  sort(t.begin(),t.end());
  int right;
  int tmp=c;
  int ans=0;
  rep(i,n){
    if(t[i].first <= right && tmp!=c){
      tmp++;
    }else{
      right = t[i].second;
      tmp=1;
      ans++;
    }
  }
  cout<<ans<<endl;
}


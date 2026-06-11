#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//DPと思ったが1e9はでかすぎ
//黒点はせいぜい1e5、それを管理すればいいかな
//1e5**はむりか
//1個うったら9マス+1
//map管理？
int main(){
  ll H,W,N; cin>>H>>W>>N;
  vector<ll> ans(10,0);
  ans[0]=(H-2)*(W-2);
  ll x[3]={-1,0,1};
  map<pair<ll,ll>,ll> mp;
  for(int i=0; i<N; i++){
    ll a,b; cin>>a>>b;
    for(int j=0; j<3; j++){
      ll aa=a+x[j];
      if(aa<=1 || aa>=H) continue;
      for(int k=0; k<3; k++){
        ll bb=b+x[k];
        if(bb<=1 || bb>=W) continue;
        ans[mp[make_pair(aa,bb)]]--;
        mp[make_pair(aa,bb)]++;
        ans[mp[make_pair(aa,bb)]]++;
      }
    }
  }
  for(int i=0; i<=9; i++) cout<<ans[i]<<endl;
}
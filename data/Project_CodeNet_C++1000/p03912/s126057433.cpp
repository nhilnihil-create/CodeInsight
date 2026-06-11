#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,m,tmp0,tmp1,ans=0,val,tmp;
  cin >> n >> m;
  ll x[n],lv;
  map<ll,ll> mp[m],t_mp;
  ll cnt[m];
  fill(cnt,cnt+m,0);
  for(int i=0;i<n;i++){
    cin >> x[i];
    mp[x[i]%m][x[i]]++;
    cnt[x[i]%m]++;
  }
  for(int i=0;i<=m/2;i++){
    if(i!=0&&!(m%2==0&&i==m/2)){
      tmp0 = cnt[i];
      tmp1 = cnt[m-i];
      if(tmp0<tmp1){
        val = tmp0;
        t_mp = mp[m-i];
        lv = tmp1-tmp0;
      }else{
        val = tmp1;
        t_mp = mp[i];
        lv = tmp0-tmp1;
      }
      for(auto j:t_mp){
        if(lv<2){
          break;
        }
        if(j.second>=2){
          tmp = min(j.second,lv);
          val += tmp/2;
          lv -= (tmp/2)*2;
        }
      }
      ans += val;
//      cout << i<<" "<<val<<endl;
    }else{
      ans += cnt[i]/2;
    }
  }
  cout << ans <<endl;
}

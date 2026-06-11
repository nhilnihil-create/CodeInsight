// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll n,m,ans=1000000000000000;
  cin >> n >> m;
  vector<ll> spo_c(m,0);
  ll a[n][m];
  set<ll> st;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  for(int i=0;i<m;i++){
    st.insert(i);
  }
  for(int i=0;i<m;i++){
    ll rm=0;
    fill(spo_c.begin(),spo_c.end(),0);
    for(int j=0;j<n;j++){
      for(int k=0;k<m;k++){
        if(st.find(a[j][k])!=st.end()){
          spo_c[a[j][k]]++;
          break;
        }
      }
    }
    for(int j=0;j<m;j++){
      if(spo_c[rm]<spo_c[j]){
        rm = j;
      }
    }
    ans = min(ans,spo_c[rm]);
    st.erase(rm);
  }
  cout << ans << endl;
}

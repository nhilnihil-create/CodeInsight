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
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(18);
}
signed main(){
  init_io();
  ll n;
  cin >> n;
  vector<ll> ans(n*n,-1),x(n),need(n);
  vector<P> px;
  queue<ll> que;
  for(int i=0;i<n;i++){
    cin >> x[i];
    x[i]--;
    px.push_back(P(x[i],i));
    ans[x[i]] = i;
    need[i] = i;
  }
  sort(px.begin(),px.end());
  for(int i=0;i<n;i++){
    for(int j=0;j<px[i].second;j++){
      que.push(px[i].second);
    }
  }
  for(int i=0;i<n*n;i++){
    if(ans[i]==-1){
      if(que.empty()){
        cout << "No\n";
        return 0;
      }
      ans[i] = que.front();
      need[que.front()]--;
      que.pop();
    }else{
      if(need[ans[i]]!=0){
        cout << "No\n";
        return 0;
      }else{
        for(int j=0;j<n-1-ans[i];j++){
          que.push(ans[i]);
        }
      }
    }
  }
  cout <<"Yes\n";
  for(int i=0;i<n*n;i++){
    cout << ans[i]+1;
    if(i==n*n-1) cout << endl;
    else cout << " ";
  }
}

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
  int w,h;
  cin >> w >> h;
  priority_queue<pair<ll,bool>,vector<pair<ll,bool>>,greater<pair<ll,bool>>> pque;
  for(int i=0;i<w;i++){
    ll p;cin >> p;
    pque.push({p,0});
  }
  for(int i=0;i<h;i++){
    ll p;cin >> p;
    pque.push({p,1});
  }
  w++;
  h++;
  ll ans = 0;
  while(w > 1 || h > 1){
    auto t = pque.top();
    pque.pop();
    if(t.second){
      if(h > 1){
        ans += t.first * w;
        h--;
      }
    }
    else{
      if(w > 1){
        ans += t.first * h;
        w--;
      }    
    }
  }
  cout << ans << endl;
}
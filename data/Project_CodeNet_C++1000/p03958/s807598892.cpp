#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  int n,t;
  cin >> n >> t;
  priority_queue<P> que;
  rep(i,t){
    int x;cin >> x;
    que.push(make_pair(x,i));
  }
  P k,l;
  int fi = que.top().second;
  while(1){
    if(que.empty())break;
    k = que.top();que.pop();
    if(que.empty()){
      que.push(k);
      break;
    }
    l = que.top();que.pop();
    if(k.first-l.first > 0)que.push(make_pair(k.first-l.first,k.second));
  }
  if(que.empty()){
    cout << 0 << endl;
  }else{
    if(que.top().second == fi){
      cout << max(0,que.top().first-1) << endl;
    }else{
      cout << max(0,que.top().first-2) << endl;
    }
  }








  return 0;
}
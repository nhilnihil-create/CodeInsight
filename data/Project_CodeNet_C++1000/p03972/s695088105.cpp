#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
  int W, H;
  cin >> W >> H;
  vector<pair<ll, int>> buf;
  for(int i=0;i<W;i++){
    ll p;
    cin >> p;
    buf.emplace_back(p, 0);
  }
  for(int i=0;i<H;i++){
    ll q;
    cin >> q;
    buf.emplace_back(q, 1);
  }
  priority_queue<
    pair<ll, int>,
    vector< pair<ll, int>>,
    greater< pair<ll, int>>>
      PQ(buf.begin(), buf.end());
  ll ans = 0;
  while(!PQ.empty()){
    auto C = PQ.top();PQ.pop();
    if(C.second == 0){
	  ans += (H + 1) * C.first;
      W--;
    }else{
      ans += (W + 1) * C.first;
      H--;
    }
  }
  cout << ans << endl;
}

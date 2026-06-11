#include <iostream> // cout, endl, cin
#include <cmath> //sqrt pow
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // dequef
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower

#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define all(a) (a).begin()+1, (a).end()
#define mod 2019
using ll = long long;
using namespace std;
int main(){
  ll n,W;
  cin >> n >> W;
  vector<vector<ll>> value(4);
  ll first;
  rep(i, n){
    ll w,v;
    cin >> w >> v;
    if(!i){
      first = w;
      rep(j, 4) value[j].push_back(0);
    }
    value[w - first].push_back(v);
  }
  rep(i, 4){
    sort(all(value[i]));
    reverse(all(value[i]));
    rep(j, value[i].size() - 1) value[i][j + 1] += value[i][j];
  }
  ll ans = 0;
  rep(a, value[0].size()){
    rep(b, value[1].size()){
      rep(c, value[2].size()){
        ll weight = a*first + b*(first+1) + c*(first+2);
        if(weight > W) break;
        ll d = min((W - weight) / (first + 3), (ll)value[3].size() - 1);
        ll res = 0;
        res += value[0][a];
        res += value[1][b];
        res += value[2][c];
        res += value[3][d];
        ans = max(ans, res);
      }
    }
  }
  cout << ans << endl;
}
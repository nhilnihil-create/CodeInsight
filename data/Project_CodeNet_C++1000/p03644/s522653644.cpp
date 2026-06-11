#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
  ll n;
  cin >> n;
  ll ans = 1, mx = 0;
  rep(i, 1, n+1){
    ll cur = i;
    ll tmp = 0;
    while(cur % 2 ==0){
      tmp++;
      cur /= 2;
    }
    if(mx < tmp){
      ans = i;
      mx = tmp;
    }
  }
  cout << ans << endl;
    return 0;
}

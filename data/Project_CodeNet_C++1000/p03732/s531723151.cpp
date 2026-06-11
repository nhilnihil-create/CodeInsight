#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n, W, w, v, wn;
  cin >> n >> W;
  
  vector<vector<ll>> info(4, vector<ll>(0));


  cin >> w >> v;
  info[0].emplace_back(v);
  for (int i = 1; i < n; i++){
    cin >> wn >> v;
    info[wn - w].emplace_back(v);
  }
  sort(info[0].begin(), info[0].end(), greater<ll>());
  sort(info[1].begin(), info[1].end(), greater<ll>());
  sort(info[2].begin(), info[2].end(), greater<ll>());
  sort(info[3].begin(), info[3].end(), greater<ll>());
  vector<vector<ll>> sum(4, vector<ll>(0));
  for (int i = 0; i < 4; i++){
    sum[i].emplace_back(0);
    for (int j = 0; j < info[i].size(); j++){
      sum[i].emplace_back(sum[i][j] + info[i][j]);
    }
  }


  ll res = 0;
  for (int i = 0; i <= info[0].size(); i++){
    for (int j = 0; j <= info[1].size(); j++){
      for (int k = 0; k <= info[2].size(); k++){
        if (w*i + (w+1)*j + (w+2)*k > W)
          break;
        else {
          ll t = (W - (w*i + (w+1)*j + (w+2)*k)) / (w + 3);
          ll a = min((ll)info[3].size(), t);
          res = max(res, sum[0][i] + sum[1][j] + sum[2][k] + sum[3][a]);
        }
      }
    }
  }
  

  cout << res << endl;
  

  return 0;
}

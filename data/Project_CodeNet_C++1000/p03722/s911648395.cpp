#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

ll INF = (ll)pow(10, 16);

int main(){
  ll N, M;
  cin >> N >> M;
  vvl abc(M, vl(3));
  rep(i, M){
    cin >> abc[i][0] >> abc[i][1] >> abc[i][2];
    abc[i][2] = -abc[i][2];
  }

  vl dist(N + 1, INF);
  dist[0] = dist[1] = 0;

  rep(i, N - 1){
    rep(j, M){
      if(dist[abc[j][0]] == INF) continue;
      
      if(dist[abc[j][1]] > dist[abc[j][0]] + abc[j][2]){
		dist[abc[j][1]] = dist[abc[j][0]] + abc[j][2];
      }
    }
  }

  ll ans = -dist[N];

  vector<bool> neg(N + 1, false);

  rep(i, N){
    rep(j, M){
      if(dist[abc[j][0]] == INF) continue;

      if(dist[abc[j][1]] > dist[abc[j][0]] + abc[j][2]){
		dist[abc[j][1]] = dist[abc[j][0]] + abc[j][2];
		neg[abc[j][1]] = true;
      }

      if(neg[abc[j][0]] == true){
		neg[abc[j][1]] = true;
      }
    }
  }

  if(neg[N])
    cout << "inf" << endl;
  else
    cout << ans << endl;
  
  return 0;
}

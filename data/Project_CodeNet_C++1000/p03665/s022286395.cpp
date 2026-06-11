#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void comb(vector<vector<ll>> &v){
  for(int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <v.size();k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}

int main() {
    ll N, P, A;
    cin >> N >> P;
    vector<vector<ll> > v(N+1,vector<ll>(N+1,0));
    vector<ll> odd, even;
    rep(i,N) {
        cin >> A;
        if (A % 2 == 0) even.push_back(A);
        else odd.push_back(A);
    }
    ll ans = 0;
    comb(v);
    ans = pow(2LL, even.size());
    ll tmp = 1;
    for (ll i = 1; i * 2 <= odd.size(); ++i) {
        tmp += v.at(odd.size()).at(i * 2);
    }
    ans *= tmp;
    if (P == 1) ans = pow(2LL, N) - ans;
    cout << ans << endl;
}


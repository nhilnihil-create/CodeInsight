#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

std::vector<std::vector<long long>> comb(int n) {
  std::vector<std::vector<long long>> v(n + 1,std::vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

int main() {
    ll N, A, B; cin >> N >> A >> B;
    vector<ll> v(N);
    std::vector<std::vector<long long>> cmb = comb(N+1);
    for (ll i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(),v.end(),greater<ll>());
    double res = 0;
    for (ll i = 0; i < A; i++) {
        res += (double) v[i];
    }
    res /= (double)A;
    vector<ll> S(N+1,v[0]);
    for (ll i = 1; i < N; i++) S[i] = S[i-1] + v[i];

    ll cnt = 0;
    //num...何個選び取るか
    for (ll num = A; num <= B; num++) {
        if (S[num-1]*A < S[A-1]*num) break;
        //bound...境界の値
        ll bound = v[num-1];
        ll i = 0, a = 0, b = 0;
        while (v[i] > bound) i++; a = i;
        while (v[i] == bound && i < N) i++; b = i;
        cnt += cmb[b-a][num-a];
    }
    /*
    tmpよりも大きい要素数a
    同じ要素数b-a
    b-aの内から、不足する要素数を選び出す
    */
    printf("%.8lf\n",res);
    cout << cnt << endl;


}

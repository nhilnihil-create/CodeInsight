#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORR(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef set<int> si;
const int inf = 1e9;
const int mod = 1e9+7;

ll N, tmp, pre, prepre, s, sq;
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  if (N == 1){
    cout << 1 << endl;
    return 0;
  }
  if (N == 2){
    cout << 4 << endl;
    return 0;
  }
  pre = N * N % mod;
  prepre = N;
  sq = (N - 1) * (N - 1);
  FOR(i, 3, N + 1){
    tmp = pre + s + sq + N - i + 2;
    tmp %= mod;
    s += prepre;
    s %= mod;
    prepre = pre;
    pre = tmp;
  }
  cout << pre << endl;
  return 0;
}

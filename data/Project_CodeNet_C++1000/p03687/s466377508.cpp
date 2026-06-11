#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S; cin >> S;
  int N = S.size();
  vector<int> cnt(26, 0); // 個数
  vector<int> A(26, -1); // 最後の位置
  vector<int> AA(26, 0); // 間の最大値
  REP(i, N){
    int a = S[i]-'a';
    cnt[a]++;
    AA[a] = max(AA[a], i-A[a]-1);
    A[a] = i;
  }
  int ans = 1e9;
  REP(i, 26){
    if(cnt[i] == 0) continue;
    int res = max(AA[i], N-1-A[i]);
    ans = min(ans, res);
  }
  cout << ans << endl;
}

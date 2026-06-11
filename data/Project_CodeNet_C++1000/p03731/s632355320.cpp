/*
　　　　　　 ＿＿
　　　　　／＞　　 フ
　　　　　| 　_　 _ l
　 　　　／` ミ＿xノ
　　 　 /　　　 　 |　見ちゃだめだよ！
　　　 /　 ヽ　　 ﾉ　　
　 　 │　　|　|　|　　
　／￣|　　 |　|　|
　| (￣ヽ＿_ヽ_)__)
　＼二つ
*/

#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const long long INF = 1LL << 60;
int main() {
  int n, T;
  cin >> n >> T;
  vector<int> t(n);
  rep(i, n) cin >> t[i];
  int total = 0;
  rep(i, n - 1) { total += min(t[i + 1] - t[i], T); }
  cout << total + T << endl;
}
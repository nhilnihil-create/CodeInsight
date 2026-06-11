#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lint ai, ao, at, aj, al, as, az;
  cin >> ai >> ao >> at >> aj >> al >> as >> az;
  lint K = ao;
  lint tmp = ai/2*2 + aj/2*2 + al/2*2;
  if(ai > 0 && aj > 0 && al > 0) tmp = max(tmp, (ai-1)/2*2 + (aj-1)/2*2 + (al-1)/2*2 + 3);
  K += tmp;
  cout << K << endl;
}
//ヘッダー
#include <bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF = 1e+9;
const int MOD = 1e+9 + 7;

//REPマクロ
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define REP2(i, a, b) for (ll i = a; i < (ll)(b); i++)
#define REPD2(i, a, b) for (ll i = a; i > (ll)(b); i--)

//vectorの扱い
#define ALL(x) (x).begin(), (x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size())      //size
#define MAX(x) *max_element(ALL(x))   //最大値
#define MIN(x) *min_element(ALL(x))   //最小値

//グローバル変数

//ライブラリ挿入

int main()
{
  string s;
  cin >> s;
  int N;
  N = s.size();
  int cnt = 0;
  int ans = 0;
  REP(i, N)
  {
    if (s[i] == 'g')
    {
      if (cnt > 0)
      {
        ans++;
        cnt--;
      }
      else
      {
        cnt++;
      }
    }
    else
    {
      if (cnt > 0)
      {
        cnt--;
      }
      else
      {
        ans--;
        cnt++;
      }
    }
  }
  cout << ans << endl;
}

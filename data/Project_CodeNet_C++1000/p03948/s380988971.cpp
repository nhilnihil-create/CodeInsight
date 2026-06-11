/*bismillah ->                                                                                                         << Suirkhanov Meyirlan >>
  GL HF


                                                                                                                      42

    bless my code =)
                                                                                                            NEVER FOLLOW YOUR RULES :D HAHAHAHA
*/


///scanf ("%d%d", &x, &y);
///printf("%d", &a)

#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio();   cin.tie(0);   cout.tie(0);
#define randoperation srand(time(0));
#define pii pair < int , int >
#define pll pair < ll, ll >
#define pb push_back
#define pf psuh_front
#define mp make_pair
#define fi first
#define se second
#define fast ios_base::sync_with_stdio();   cin.tie(0);   cout.tie(0);
#define randoperation srand(time(0));
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll N = 2 * 1e5 + 7;
const ld pi = 3.14159265359;
const int INF = 1e20 + 7;
const double eps = 1e-9;

const int xi[4] = {-1, 0, +1, 0};
const int yj[4] = {0, +1, 0, -1};
const int xxi[4] = {+1, 0, -1, 0};
const int yyj[4] = {0, -1, 0, +1};

int n, m, a[N], mn = INF;

map < int, int > cnt;

int main(){

  //freopen("bridge.in", "r", stdin);
  //freopen("bridge.out", "w", stdout);

  fast
  randoperation;

  ///           ||
  ///start here \/

  cin >> n >> m;

  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }

  for(int i = 1; i <= n; i++){
    mn = min(mn, a[i]);
    cnt[a[i] - mn]++;
  }

  cout << cnt.rbegin() -> second;
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Tapris = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N, M, D;
  cin >> N >> M >> D;
  int d = D*2;

  char color[2][2] = {{'R', 'Y'}, {'G', 'B'}};

  vector<string> mas(N, "");


  rep(i, N) rep(j, M) {
    int x = ((i-j)%d+d)%d;
    int y = (i+j)%d;
    //cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<color[x<D][y<D]<<endl;
    mas[i] += color[x<D][y<D];
  }

  rep(i, N) cout << mas[i] << endl;

  return 0;
}

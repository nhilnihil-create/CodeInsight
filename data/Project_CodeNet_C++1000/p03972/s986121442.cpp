#include <bits/stdc++.h> 
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
        #define eprintf(...) 42
#endif

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define foreach(u,v) for(auto (u) : (v))
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

const int inf = 1e9;
const ll linf = 1LL<<60;
const ll mod = 1e9 + 7;
const double eps = 1e-9;

/*
  N = W*H
  |E| = N-1
*/

int main()
{
  int w, h;
  cin >> w >> h;

  vi p(w), q(h);
  rep(i, w) cin >> p[i];
  rep(j, h) cin >> q[j];

  priority_queue<pii, vector<pii>, greater<pii>> que;  
  rep(i, w) que.push(mp(p[i], 0));
  rep(j, h) que.push(mp(q[j], 1));

  w++; h++;
  ll ans = 0;
  while(!que.empty()){
    pii a = que.top();
    que.pop();

    if(a.second == 0){
      ans += (ll)h*a.first;
      w--;
    }else{
      ans += (ll)w*a.first;
      h--;
    }
//    cout << a.first << "," << a.second << " : " << ans << endl;
  }

  cout << ans << endl;

  return 0;
}

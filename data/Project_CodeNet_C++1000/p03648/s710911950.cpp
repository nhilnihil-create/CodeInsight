#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> point;

const int MAXN = 55;

ll a[MAXN];

int main(){
  ll k; cin >> k;
  cout << 50 << "\n";
  ll add = k / 50;
  ll ostatak = k % 50;

  REP(i, 50)
    a[i] = add + 49;
  REP(i, 50){
    if(ostatak > i)
      a[i] ++;
    else if(ostatak)
      a[i] -= ostatak;
    cout << a[i] << " ";
  }
}

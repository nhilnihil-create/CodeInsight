#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
}*/

signed main()
{
  int k;
  cin >> k;

  int n = 50;
  vi v(n);

  if(k < n){
    rep(i, k) v[i] = n-i;
  }else{
    int q = k/50;
    int r = k%50;
    
    iota(all(v), 1);
    reverse(all(v));

    rep(i, n){
      v[i] += (q-1);
    }

    rep(i, r){
      v[i]++;
    }
  }

  cout << n << endl;
  rep(i, n){
    cout << v[i] << " \n"[i == n-1];
  }

  return 0;
}

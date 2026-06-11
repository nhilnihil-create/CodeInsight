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

ll k, a[50];
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> k;
  ll b = 49 + k/50, m = k%50;
  cout << 50 << endl;
  FOR(i, 0, m){
    a[i] = b + 50 - (m - 1);
  }
  FOR(i, m, 50){
    a[i] = b - m;
  }
  FOR(i, 0, 49) cout << a[i] << " ";
  cout << a[49] << endl;
}
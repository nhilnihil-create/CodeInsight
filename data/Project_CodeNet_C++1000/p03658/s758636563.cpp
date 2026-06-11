#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589;

int main(){
  int n, k;
  cin >> n >> k;
  int l[50];
  rep(i, n) cin >> l[i];
  sort(l, l+n);
  reverse(l, l+n);
  int ans = 0;
  rep(i, k){
    ans += l[i];
  }
  cout << ans <<endl;
}
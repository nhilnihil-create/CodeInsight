#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define REPll(i, n) for(ll i = 0; i < (ll)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
typedef vector<bool>    vecbool;
typedef vector<int>     vecint;
typedef vector<ll>      vecll;
typedef vector<string>  vecstr;
typedef vector<vecint>  vec2int;
typedef vector<vecbool> vec2bool;
int dx[4] {-1,+1, 0, 0};
int dy[4] { 0, 0,-1,+1};
int gcd(int a, int b){
  if(b == 0){
    return a;
  }
  if(a < b)return gcd(b, a);
  return gcd(b, a%b);
}

int main()
{
  int n, k; cin >> n >> k;
  vecint a(n,0);REP(i,n) cin >> a[i];
  sort(all(a));
  if(a[n - 1] < k){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  int x = gcd(a[0],a[1]);
  REP(i,n){
    x = gcd(x, a[i]);
    if(x == 1){break;}
  }
  // cout << x << endl;
  if(k%x == 0){
    cout << "POSSIBLE" << endl;
  }else{
    cout << "IMPOSSIBLE" << endl;
  }
}

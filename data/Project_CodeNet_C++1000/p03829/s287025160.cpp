#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  queue<ll> x;
  rep(i, n){
    ll u;
    cin >> u;
    x.push(u);
  }
  ll ans = 0;
  ll current = x.front();
  x.pop();
  while(!x.empty()){
    ll next = x.front();
    x.pop();
    ans += min(a * (next - current),  b);
    current = next;
  }
  cout << ans <<endl;
  
}
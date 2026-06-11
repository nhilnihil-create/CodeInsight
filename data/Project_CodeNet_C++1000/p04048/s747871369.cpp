#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define reps(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   reps(i,0,n)
#define all(x) (x).begin(),(x).end()
#define INF (1000000010)
#define MOD (1000000007)
#define PI (acos(-1))

ll ans;
void rec(ll x,ll y){
  if(y%x==0){
    ans += 2*y-x;
  }else{
    ans += 2*x*(y/x);
    rec(y%x,x);
  }
}

int main(){
  ll n,x;
  cin >> n >> x;
  ans = n;
  rec(min(x,n-x),max(x,n-x));
  cout << ans << endl;
}
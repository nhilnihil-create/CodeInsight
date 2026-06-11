#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

void yes(){
  cout << "YES" << endl;
  exit(0);
}

void no(){
  cout << "NO" << endl;
  exit(0);
}

int main(){
  ll n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  REP(k,n){
    ll lb = a+k*c+(n-1-k)*(-d);
    ll ub = a+k*d+(n-1-k)*(-c);
    if(lb<=b && b<=ub) yes();
  }
  no();
}


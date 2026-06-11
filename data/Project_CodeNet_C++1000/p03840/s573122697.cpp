#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 100000000000000 //14

int main(){
    ll x, p, n1, y, z, n2, n3; cin >> x >> p >> n1 >> y >> z >> n2 >> n3;
    ll ans = p+(x/2+y/2+z/2)*2;
    ll xx = x%2;
    ll yy = y%2;
    ll zz = z%2;
    if (x!=0&&xx==0&&yy==1&&zz==1) ans+= 1;
    else if (y!=0&&xx==1&&yy==0&&zz==1) ans+=1;
    else if (z!=0&&xx==1&&yy==1&&zz==0) ans+=1;
    else if (xx==1&&yy==1&&zz==1) ans += 3;
    
    cout << ans << endl;
}
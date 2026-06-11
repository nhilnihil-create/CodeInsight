#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

ll I, O, T, J, L, S, Z;

ll calc(ll i, ll j, ll l){
    ll res=0;
    res+=i-(i%2);
    res+=j-(j%2);
    res+=l-(l%2);
    if(i&&j&&l){
        ll other=0, ii=i, jj=j, ll=l;
        ii--,jj--,ll--;
        other+=3;
        other+=ii-(ii%2);
        other+=jj-(jj%2);
        other+=ll-(ll%2);
        if(res<other) res=other;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>I>>O>>T>>J>>L>>S>>Z;
    
    ll cnt=0;
    cnt+=O;
    cnt+=calc(I,J,L);
    cout1(cnt);
}
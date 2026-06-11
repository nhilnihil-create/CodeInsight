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

#define rep(i,a) for(int i=0; i<a; i++)
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

bool check(ll n){
    cout2("?",n);
    char c; cin>>c;
    return (c=='Y');
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll num=1000000000;
    while(num&&!check(num)) num/=10;
    
    if(num!=1000000000){
        ll lb=num*10, ub=lb*10-1, mid;
        while(ub-lb>1){
            mid=(ub+lb)/2;
            if(check(mid)) ub=mid;
            else lb=mid;
        }
        ll ans=lb;
        if(!check(ans))ans++;
        cout2("!",ans/10);
    }else{
        ll ans=9;
        while(!check(ans)) ans*=10;
        cout2("!",ans/9);
    }
    return 0;
}
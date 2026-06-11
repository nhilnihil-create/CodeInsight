#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;

int main(){
    ll ans=0;
    ll a,b,c; cin>>a>>b>>c;

    ll v1=(a-a/2)*b*c - a/2*b*c;
    ll v2=(b-b/2)*a*c - b/2*a*c;
    ll v3=(c-c/2)*b*a - c/2*b*a;

    cout<<min(v1,min(v2,v3))<<endl;

}
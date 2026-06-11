#include <bits/stdc++.h>
using namespace std;
 
#define oo 1e18
#define fi first
#define se second
#define sp(iiii) setprecision(iiii)
#define IO ios_base::sync_with_stdio(false); cin.tie(0)
#define ms(aaaa,xxxx) memset(aaaa,xxxx,sizeof(aaaa))
#define cntbit(xxxx) __builtin_popcount(xxxx)
#define getbit(xxxx,aaaa) ((xxxx>>(aaaa-1))&1)
#define _cos(xxxx) cos(xxxx*acos(-1)/180)
#define _sin(xxxx) sin(xxxx*acos(-1)/180)
#define _tan(xxxx) tan(xxxx*acos(-1)/180)
#define PE cout<<fixed
#define sqr(x) ((x)*(x))
 
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,long long> plll;
 
const ld pi=acos(-1);

ll n,l,r,x,y,i;

int main() {
    IO;
    cin>>n;
    cin>>l>>r;
    for (i=2;i<=n;i++) {
        cin>>x>>y;
        l=x*max((l+x-1)/x,(r+y-1)/y);
        r=y*max((l+x-1)/x,(r+y-1)/y);
    }
    cout<<l+r<<'\n';
}
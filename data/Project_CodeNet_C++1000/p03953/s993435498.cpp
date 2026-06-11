#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;

using D=double;
const int N=100010;
int n,m;
ll k;
D x[N];

int main() {
    scanf("%d",&n);
    rep(i,0,n) scanf("%lf",&x[i]);
    scanf("%d %lld",&m,&k);
    vi pm(n-1);
    iota(pm.begin(),pm.end(),0);
    rep(i,0,m) {
        int p;
        scanf("%d",&p); p--;
        swap(pm[p],pm[p-1]);
    }

    auto trans=[&](vi &f,vi &g) {
        vi h(n-1);
        rep(i,0,n-1) h[i]=f[g[i]];
        return h;
    };

    vi r(n-1);
    iota(r.begin(),r.end(),0);
    while (k) {
        if (k&1) r=trans(r,pm);
        pm=trans(pm,pm);
        k>>=1;
    }

    D c=x[0];
    printf("%.20lf\n",c);
    rep(i,0,n-1) {
        c+=x[r[i]+1]-x[r[i]];
        printf("%.20lf\n",c);
    }
}
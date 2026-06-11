#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef vector<pii> vpii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
    tree_order_statistics_node_update> ost;

const int N=110000;
ll n, l, x[N], w[N], xe[N];
ll np, yyp[N], nn, yyn[N];

ll getx(ll k) {
    ll q=k/2;
    if((w[0]==1 && k%2==0) || (w[0]==l-1 && k%2==1))
        return -l*(q/nn)+yyn[q%nn];
    return l*(q/np)+yyp[q%np];
}

void outp(ll pos, ll dis) {
    ll i, j;
    for(i=0; i<n; i++) if(xe[i]==pos) break;
    if(dis && i<n-1 && xe[i+1]==xe[i]) i++;
    for(j=0; j<n; j++) {
        printf("%lld\n", xe[i]);
        i=(i+1)%n;
    }
}

int main() {
    ll i, t, kl, kr, km, x1, x2;
    scanf("%lld%lld%lld", &n, &l, &t);
    for(i=0; i<n; i++) {
        scanf("%lld%lld", &x[i], &w[i]);
        if(w[i]==2) w[i]=l-1;
        xe[i]=(x[i]+w[i]*t)%l;
    }
    sort(xe, xe+n);
    for(i=0; i<n; i++) if(w[i]==l-1) yyp[np++]=x[i];
    if(w[0]==1) yyn[nn++]=x[0];
    for(i=n-1; i>0; i--) if(w[i]==1) yyn[nn++]=-l+x[i];
    if(np==0 || nn==0) {
        outp((x[0]+w[0]*t)%l, 0);
        return 0;
    }
    kl=0; kr=2*t+1;
    while(kl<kr) {
        km=(kl+kr)/2;
        x1=getx(km);
        x2=getx(km+1);
        if(abs(x1-x2)>2*t) kr=km;
        else kl=km+1;
    }
    x1=getx(kl);
    if((w[0]==1 && kl%2==0) || (w[0]==l-1 && kl%2==1)) x2=1;
    else x2=l-1;
    outp((x1%l+l+x2*t)%l, (x2==1));
    return 0;
}
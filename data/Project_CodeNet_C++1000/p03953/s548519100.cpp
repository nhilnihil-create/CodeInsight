#include <bits/stdc++.h>
#define pb push_back
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int N=110000;
ll x[N], s[N], t[N], buf[N];

int main() {
    ll i, j, k, l, m, n, q;
    scanf("%lld", &n);
    for(i=1; i<=n; i++) scanf("%lld", &x[i]);
    scanf("%lld%lld", &m, &k);
    for(i=1; i<=n; i++) s[i]=i;
    while(m--) {
        scanf("%lld", &i);
        swap(s[i], s[i-1]);
    }
    for(i=1; i<=n; i++) {
        t[s[i]]=i;
        s[i]=0;
    }
    for(i=1; i<=n; i++) if(!s[i]) {
        j=i, q=0;
        do {
           buf[q++]=j;
           j=t[j];
        } while(i!=j);
        j=i, l=k%q;
        do {
            s[j]=buf[l];
            l=(l+1)%q;
            j=t[j];
        } while(j!=i);
    }
    for(i=0; i<=n; i++) buf[i]=0;
    for(i=1; i<=n; i++) {
        buf[s[i-1]+1]+=x[i];
        buf[s[i]+1]-=x[i];
    }
    for(i=1; i<=n; i++) {
        buf[i]+=buf[i-1];
        printf("%lld\n", buf[i]);
    }
    return 0;
}
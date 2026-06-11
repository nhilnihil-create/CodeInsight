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

const int N=510;
vpii q;
int c, ans[N*N];

void put(int w, int dir) {
    while(ans[c]) c+=dir;
    ans[c]=w;
    c+=dir;
}

int main() {
    int i, n, t;
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
        scanf("%d", &t);
        q.pb(pii(t, i));
        ans[t]=i;
    }
    sort(all(q));
    c=1;
    for(auto z:q) {
        for(i=1; i<z.sc; i++) put(z.sc, 1);
        if(c>z.fs) return printf("No\n"), 0;
    }
    reverse(all(q));
    c=n*n;
    for(auto z:q) {
        for(i=n; i>z.sc; i--) put(z.sc, -1);
        if(c<z.fs) return printf("No\n"), 0;
    }
    printf("Yes\n");
    for(i=1; i<=n*n; i++)
        printf(i==n*n? "%d\n":"%d ", ans[i]);
    return 0;
}
#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;
const lint mod = 1e9 + 7;

typedef struct Segtree{
    int n = 1;
    vector<int> node;
    
    Segtree(int n_){
        while(n < n_) n *= 2;
        node.resize(2*n-1, 0);
    }
    
    void update(int a, int b, int i, int l, int r, int v){
        if(r<=a || b<=l) return;
        if(a<=l && r<=b){
            node[i] += v;
            return;
        }
        update(a, b, 2*i+1, l, (l+r)/2, v);
        update(a, b, 2*i+2, (l+r)/2, r, v);
    }
    
    int getval(int i){
        i += n-1;
        int ret = node[i];
        while(i){
            i = (i-1) / 2;
            ret += node[i];
        }
        return ret;
    }
}ST;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    pii p[n];
    rep(i, n){
        int l, r;
        scanf("%d%d", &l, &r);
        p[i] = make_pair(l, r);
    }
    sort(p, p+n, [](const pii &a, const pii &b){return a.se-a.fi < b.se-b.fi;});
    ST st(m+1);
    int cur = 0;
    For(i, 1, m+1){
        while(cur < n && p[cur].se-p[cur].fi+1 <= i){
            st.update(p[cur].fi, p[cur].se+1, 0, 0, st.n, 1);
            ++cur;
        }
        int ans = n - cur;
        for(int j=0; j<=m; j+=i) ans += st.getval(j);
        printf("%d\n", ans);
    }
}
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
#define s second
#define f first


struct BIT {
    vector<long long> v;

    BIT(int s) {
        resize(s);
    }

    void clear() {
        v.clear();
    }

    BIT() {
    }

    void resize(int s) {
        s = 1 << (int) ceil(log(1.0 * s) / log(2.) + 1e-9);
        v.resize(s);
    }

    long long get(int i) {
        i++;
        long long r = 0;
        while (i) {
            r += v[i - 1];
            i -= i & -i;
        }
        return r;
    }

    void add(int i, long long val) {
        i++;
        while (i <= (int) v.size()) {
            v[i - 1] += val;
            i += i & -i;
        }
    }

    int find(long long val) {
        int s = 0;
        int m = v.size() >> 1;
        while (m) {
            if (v[s + m - 1] < val)
                val -= v[(s += m) - 1];
            m >>= 1;
        }
        return s;
    }
};


int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    vector<piii> vp(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &vp[i].second.f, &vp[i].s.s);
        vp[i].first = vp[i].second.s - vp[i].second.f + 1;
    }
    sort(vp.begin(), vp.end());

    BIT bit(400005);
    int ind = 0;
    for (int i = 1; i <= m; i++) {
        while(ind < vp.size() && i > vp[ind].f){
            bit.add(vp[ind].s.f, 1);
            bit.add(vp[ind].s.s+1, -1);
            ind++;
        }
        int res = 0;
        for(int j=i; j<=m; j+=i){
            res += bit.get(j);
        }
        res += (int)vp.size() - ind;
        printf("%d\n", res);
    }
}

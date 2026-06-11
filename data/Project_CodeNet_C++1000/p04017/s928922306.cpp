#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Doubling
{
    const int LOG;
    vector< vector< int > > table;
    
    Doubling(int sz, int64_t lim_t) : LOG(64 - __builtin_clzll(lim_t))
    {
        table.assign(LOG, vector< int >(sz, -1));
    }

    void set_next(int k, int x)
    {
        table[0][k] = x;
    }

    void build()
    {
        for(int k = 0; k + 1 < LOG; k++) {
            for(int i = 0; i < table[k].size(); i++) {
                if(table[k][i] == -1) table[k + 1][i] = -1;
                else table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int query(int k, int64_t t)
    {
        for(int i = LOG - 1; i >= 0; i--) {
            if((t >> i) & 1) k = table[i][k];
        }
        return k;
    }
};


int main(void) {
    int N;
    cin >> N;
    vector<int> x(N);
    for(int i=0; i<N; i++) {
        cin >> x[i];
    }
    
    int L;
    cin >> L;
    vector<int> l(N), r(N);
    for(int i=0; i<N; i++) {
        l[i] = distance(x.begin(), lower_bound(x.begin(), x.end(), x[i] - L));
        r[i] = distance(x.begin(), upper_bound(x.begin(), x.end(), x[i] + L)) - 1;
        // cerr << l[i] << ' ' << r[i] << endl;
    }

    Doubling left(N, 1000000), right(N, 1000000);
    for(int i=0; i<N; i++) {
        left.set_next(i, l[i]);
        right.set_next(i, r[i]);
    }
    left.build();
    right.build();

    int Q;
    cin >> Q;
    while(Q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if(a < b) {
            int ok = 100000;
            int ng = 0;
            while(ok > ng + 1) {
                int mid = (ok + ng) / 2;
                if(right.query(a, mid) >= b) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            cout << ok << endl;
        } else {
            int ok = 100000;
            int ng = 0;
            while(ok > ng + 1) {
                int mid = (ok + ng) / 2;
                if(left.query(a, mid) <= b) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            cout << ok << endl;
        }
    }
    return 0;
}

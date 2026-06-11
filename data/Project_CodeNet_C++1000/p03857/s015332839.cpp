#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class UnionFind {
public:
    // parent node index if not root index
    // minus size of the tree if root index
    std::vector<int> data;

    UnionFind( int n ) {
        data.resize( n, -1 );
    }

    int find( int x ) {
        if ( data[x] < 0 ) {
            return x;
        } else {
            int r = find( data[x] );
            data[x] = r;
            return r;
        }
    }

    void unite( int x, int y ) {
        int r = find( x );
        int s = find( y );
        if ( r != s ) {
            data[r] += data[s];
            data[s] = r;
        }
    }
};


void solve() {
    ll N, K, L;
    cin >> N >> K >> L;
    UnionFind uw(N), ut(N);
    int a,b;
    for ( int i = 0; i < K; i++ ) {
        cin >> a >> b;
        a--, b--;
        uw.unite(a, b);
    }
    for ( int i = 0; i < L; i++ ) {
        cin >> a >> b;
        a--, b--;
        ut.unite(a, b);
    }
    map<pair<int,int>, int> num;
    for ( int i = 0; i < N; i++ ) {
        num[make_pair(uw.find(i), ut.find(i))]++;
    }
    for ( int i = 0; i < N; i++ ) {
        cout << num[make_pair(uw.find(i), ut.find(i))] << " ";
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}
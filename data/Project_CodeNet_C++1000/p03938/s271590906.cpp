#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <limits>
#include <math.h>
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define RREP(i,n) for(int i=(n)-1; i>=0; --i)
#define SREP(i,s,n) for(int i=(s), i##_len=(n); i<i##_len; ++i)


using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

template <typename T>
T gcd(T a, T b) {
    if(a < b) gcd(b, a);
    if (b == 1) return 1;
    T r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    return (a.first*a.first + a.second*a.second) > (b.first*b.first + b.second*b.second);
}

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    
    UnionFind(int n = 1) {
        init(n);
    }
    
    void init(int n = 1) {
        par.resize(n); rank.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            rank[i] = 0;
        }
    }
    
    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};

#define MOD (1000000007)


int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<pair<ll, ll>> p(N);
    REP(i, N) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end());
    vector<ll> A(N), B(N);
    A[0] = p[0].second;
    SREP(i, 1, N) {
        if (p[i-1].second < p[i].second) {
            A[i] = A[i-1]+ p[i].second - p[i-1].second + 1;
            B[i] = p[i].second - A[i];
        } else {
            B[i] = B[i-1]+ p[i].second - p[i-1].second - 1;
            A[i] = p[i].second - B[i];
        }
    }
    
    REP(i, N) {
        cout << A[i] - A[0] + 1 << " ";
    }
    cout << endl;
    REP(i, N) {
        cout << B[i] - B[N-1] + 1 << " ";
    }
    cout << endl;
}

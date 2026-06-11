#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

template< class T >
struct BinaryIndexedTree
{
    vector< T > data;

    BinaryIndexedTree(int sz)
    {
        data.assign(++sz, 0);
    }

    T sum(int k)
    {
        T ret = 0;
        for(++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }

    void add(int k, T x)
    {
        for(++k; k < data.size(); k += k & -k) data[k] += x;
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    vector<vp> data(m+1);
    rep(i, n) {
        int2(a, b);
        data[b-a+1].pb({a, b});
    }

    BinaryIndexedTree<int> bit(m+2);
    int sum = n;
    Rep(i, m+1) {
        rep(j, data[i].size()) {
            bit.add(data[i][j].fir, 1);
            bit.add(data[i][j].sec+1, -1);
        }
        sum -= data[i].size();
        int ret = sum;
        for (int j = i; j <= m; j += i) {
            ret += bit.sum(j);
        }
        std::cout << ret << std::endl;
    }

    return 0;
}


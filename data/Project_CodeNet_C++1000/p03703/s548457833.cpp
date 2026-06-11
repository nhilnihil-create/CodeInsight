#include<algorithm>
#include<cassert>
#include<cfloat>
#include<climits>
#include<cmath>
#include<cstring>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

using lint = long long;
using P = pair<int, int>;
using LLP = pair<long long, long long>;

#define REP(i, x, n) for(int i = (x), i##_len = int(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = int(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = int(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = int(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = int(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())
#define TWINS(x) cout << ((x) ? "Yay!" : ":(") << endl

constexpr int IINF = (1 << 30) - 1;
constexpr long long LLINF = 1LL << 61;
constexpr double EPS = 1e-8;

constexpr int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
constexpr int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

template<class T>
class BinaryIndexedTree{
    int n;
    vector<T> bit;

public:
    BinaryIndexedTree(int _n = 0){
        init(_n);
    }

    BinaryIndexedTree(const vector<T> &v){
        build(v);
    }

    void init(int _n = 0){
        n = _n;
        bit.clear();
        bit.resize(n + 1);
        return;
    }

    void build(const vector<T> &v){
        int _n = v.size();
        init(_n);

        for(int i = 0 ; i < _n ; ++i){
            add(i + 1, v[i]);
        }

        return;
    }

    bool add(int i, T x){
        if(i <= 0 || n < i){
            return false;
        }

        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }

        return true;
    }

    bool update(int i, T x){
        T _x = x - sum(i - 1, i);
        return add(i, _x);
    }

    T sum(int i){
        T s = T(0);
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    T sum(int l, int r){
        return sum(r) - sum(l);
    }

    int lower_bound(T x){
        int i = 1, res = 0;
        while((i << 1) <= n){
            i <<= 1;
        }

        while(i > 0){
            if(res + i <= n && bit[res + i] < x){
                x -= bit[res + i];
                res += i;
            }
            i >>= 1;
        }

        return res + 1;
    }

    int upper_bound(T x){
        int i = 1, res = 0;
        while((i << 1) <= n){
            i <<= 1;
        }

        while(i > 0){
            if(res + i <= n && bit[res + i] <= x){
                x -= bit[res + i];
                res += i;
            }
            i >>= 1;
        }

        return res + 1;
    }
};

template<class T>
class CoordinateCompression{
    vector<T> dat;
    int s;

public:
    CoordinateCompression(const vector<T>& dat_, int s_ = 0){
        build(dat_, s_);
    }

    void build(const vector<T>& dat_, int s_ = 0){
        dat = dat_;

        sort(dat.begin(), dat.end());
        dat.erase(unique(dat.begin(), dat.end()), dat.end());

        s = s_;

        return;
    }

    int get(T x){
        return (int)(lower_bound(dat.begin(), dat.end(), x) - dat.begin()) + s;
    }

    T restore(int k){
        return dat[k];
    }
};

template<typename T>
bool chmax(T& a, T b, bool equal = false){
    if(a < b || equal && a == b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T& a, T b, bool equal = false){
    if(b < a || equal && a == b){
        a = b;
        return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    lint k;
    cin >> n >> k;

    vector<lint> a(n);
    rep(i, n){
        cin >> a[i];
    }

    vector<lint> v(n + 1);
    reps(i, n){
        v[i] = v[i - 1] + a[i - 1];
    }

    rep(i, n + 1){
        v[i] -= k * (lint)i;
    }

    CoordinateCompression<lint> c(v, 1);

    BinaryIndexedTree<lint> bit(n + 1);

    lint ans = 0;
    rep(i, n + 1){
        int j = c.get(v[i]);
        ans += bit.sum(j);
        bit.add(j, 1LL);
    }

    cout << ans << endl;

    return 0;
}
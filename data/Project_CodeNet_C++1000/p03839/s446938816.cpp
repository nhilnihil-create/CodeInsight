#include <bits/stdc++.h>
using namespace std;

#define Gene template< class
#define Rics printer& operator,
Gene c> struct rge{c b, e;};
Gene c> rge<c> range(c i, c j){ return {i, j};}
struct printer{
    ~printer(){cerr<<endl;}
    Gene c >Rics(c x){ cerr<<boolalpha<<x; return *this;}
    Rics(string x){cerr<<x;return *this;}
    Gene c, class d >Rics(pair<c, d> x){ return *this,"(",x.first,", ",x.second,")";}
    Gene ... d, Gene ...> class c >Rics(c<d...> x){ return *this, range(begin(x), end(x));}
    Gene c >Rics(rge<c> x){
        *this,"["; for(auto it = x.b; it != x.e; ++it)
            *this,(it==x.b?"":", "),*it; return *this,"]";}
};
#define debug() cerr<<"LINE "<<__LINE__<<" >> ", printer()
#define dbg(x) "[",#x,": ",(x),"] "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r) (rng);
}


int main() {
//    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    vector<long long> cum(n), pos(n), neg(n);
    for(int i = 0; i < n; i++) {
        cum[i] = (i > 0 ? cum[i-1] : 0) + a[i];
        pos[i] = (i > 0 ? pos[i-1] : 0) + max(a[i], 0);
        neg[i] = (i > 0 ? neg[i-1] : 0) + (a[i] < 0 ? -a[i] : 0);
    }
    for(int i = 0; i+K-1 < n; i++) {
        long long block_sum = cum[i+K-1] - (i > 0 ? cum[i-1] : 0);
        long long cur = (i > 0 ? pos[i-1] : 0) + (pos[n-1]-pos[i+K-1]) + max(block_sum, 0LL);
        ans = max(ans, cur);
    }
    cout << ans << endl;
}




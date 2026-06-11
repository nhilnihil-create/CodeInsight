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
    vector<long long> a(7);
    for(int i = 0; i < 7; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    long long t = min({a[0], a[3], a[4]});
    for(long long i = 0; i <= min(t, 1ll); i++) {
        long long x = a[0]-i, y = a[3]-i, z = a[4]-i;
        long long cur = a[1] + i*3 + (x/2)*2 + (y/2)*2 + (z/2)*2;
        ans = max(ans, cur);
    }
    cout << ans << endl;
}




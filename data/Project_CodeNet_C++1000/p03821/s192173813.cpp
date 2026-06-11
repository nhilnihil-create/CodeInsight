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


typedef long long LL;

int main() {
//    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    LL ans = 0;
    LL last = 0;
    vector<pair<LL,LL>> v;
    for(int i = 0; i < n; i++) {
        LL a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    reverse(v.begin(), v.end());
    for(auto t : v) {
        LL a = t.first, b = t.second;
        LL lo = 0, hi = 1e18/b;
        while(hi > lo) {
            LL mid = lo+hi>>1;
            if(b * mid >= a + last) hi = mid;
            else lo = mid+1;
        }
        last = lo*b-a;
//        debug(), dbg(last);
    }
    cout << last << endl;
}




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

void NO() {
    cout << "Impossible" << endl;
    exit(0);
}

void YES() {
    cout << "Possible" << endl;
    exit(0);
}

int main() {
//    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    multiset<int> s;
    int n;
    cin >> n;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
        mx = max(mx, x);
    }
    if(s.count(mx) == 1) NO();
    s.erase(s.find(mx));
    s.erase(s.find(mx));

    for(int x = 1; x < mx; x++) {
        int y = max(x, mx - x);
        if(s.find(y) == s.end()) NO();
        s.erase(s.find(y));
    }
    while(s.size() > 0) {
        auto x = *s.begin();
        if(x < (mx+1)/2 + 1) NO();
        s.erase(x);
    }
    YES();
}




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

    int n, L;
    cin >> n >> L;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i+1 < n; i++) {
        if(a[i] + a[i+1] >= L) {
//            cout << "i: " << i << endl;
            cout << "Possible" << "\n";
            int At = n-1;
            while(At > i+1) {
                cout << At << "\n";
                At--;
            }
            At = 1;
            while(At <= i+1) {
                cout << At << "\n";
                At++;
            }
            return 0;
        }
    }
    cout << "Impossible" << endl;
}




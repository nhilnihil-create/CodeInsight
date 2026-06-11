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

    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(n == 1) {
        cout << "YES" << endl;
        return 0;
    }
    long long each = 1ll*n*(n+1)/2;
    if(sum % each > 0) {
        cout << "NO" << endl;
        return 0;
    }
    else {
        if(n == 2) {
            if(2 * min(a[0], a[1]) <= max(a[0], a[1])) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            return 0;
        }
        long long tot_moves = sum/each;
        for(int i = 0; i < n; i++) {
            long long dif = a[(i+1)%n] - a[i];
            debug(), dbg(dif);
            if(tot_moves - dif < 0) {
                cout << "NO" << endl;
                return 0;
            }
            if((tot_moves - dif) % n > 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
}




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

const int N = 505;

int a[N], b[N * N];

int main() {
//    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    queue<int> q;
    for(int i = 1; i <= n*n; i++) {
        if(b[i] == 0) q.push(i);
        else {
            int remaining = b[i]-1;
            if(remaining > q.size()) {
                cout << "No" << endl;
                return 0;
            }
            while(remaining--) {
                int idx = q.front(); q.pop();
                b[idx] = b[i];
            }
        }
    }
    while(q.size() > 0) q.pop();
    vector<bool> done(n + 1);
    for(int i = n*n; i >= 1; i--) {
        if(b[i] == 0) q.push(i);
        else {
            if(done[b[i]]) continue;
            done[b[i]] = true;
            int remaining = n-b[i];
            if(remaining > q.size()) {
                cout << "No" << endl;
                return 0;
            }
            while(remaining--) {
                int idx = q.front(); q.pop();
                b[idx] = b[i];
            }
        }
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= n*n; i++) cout << b[i] << " ";
}




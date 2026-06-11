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
    vector<int> cnt(n+1), depth(n+1);
    vector<int> defeated(n+1);
    for(int i = 2; i <= n; i++) {
        cin >> defeated[i];
        cnt[defeated[i]]++;
    }
    set<pair<int,int>> leafs;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 0) {
            leafs.insert({depth[i], i});
        }
    }
    int itr = n-1;
    while(itr--) {
        auto t = *leafs.begin();
        leafs.erase(t);
        int x = t.second;
        cnt[defeated[x]]--;
        depth[defeated[x]] = 1+max(depth[defeated[x]], depth[x]);
        if(cnt[defeated[x]] == 0) {
            leafs.insert({depth[defeated[x]], defeated[x]});
        }
    }
    cout << depth[1] << endl;
}




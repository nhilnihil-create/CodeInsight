#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define repr(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = 1e9 + 10;
const long long LLINF = (long long)1e18 + 10;
const long long MOD = (long long)1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

struct unionFind{

    vector<int> par, rank;

    void init(int n){
        par.resize(n);
        rank.resize(n, 0);
        for(int i = 0 ; i < n ; ++i){
            par[i] = i;
        }
        return;
    }

    int root(int x){
        if(par[x] == x){
            return x;
        }else{
            par[x] = root(par[x]);
            return par[x];
        }
    }

    bool unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry){
            return false;
        }
        if(rank[rx] < rank[ry]){
            par[rx] = ry;
        }else if(rank[rx] == rank[ry]){
            par[rx] = ry;
            rank[ry]++;
        }else{
            par[ry] = rx;
        }
        return true;
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector< vector<int> > g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    deque<int> ans = {0, g[0][0]};

    unionFind uf;
    uf.init(n);
    uf.unite(0, g[0][0]);

    bool flag = true;
    while(flag){
        flag = false;
        for(auto x : g[ans.front()]){
            if(uf.unite(ans.front(), x)){
                flag = true;
                ans.push_front(x);
                break;
            }
        }
        for(auto x : g[ans.back()]){
            if(uf.unite(ans.back(), x)){
                flag = true;
                ans.push_back(x);
                break;
            }
        }
    }

    cout << ans.size() << endl;

    rep(i, ans.size()){
        cout << ans[i] + 1;
        if(i < i_len - 1){
            cout << " ";
        }else{
            cout << endl;
        }
    }

    return 0;
}
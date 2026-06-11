#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

struct node{
    pair<ll, ll> parent = {-1, -1};
    vector<pair<ll, ll>> child;
};

ll n; 
vector<node> tree;

void bfs(ll node, vector<ll> &dist){
    vector<ll> color(n, 0);
    color[node] = 1;
    dist[node] = 0;
    queue<ll> que;
    que.push(node);

    while(!que.empty()){
        auto p = que.front();
        que.pop();

        if(tree[p].parent.first != -1 && color[tree[p].parent.first] == 0){
            que.push(tree[p].parent.first);
            dist[tree[p].parent.first] = dist[p]+tree[p].parent.second;
            color[tree[p].parent.first] = 1;
        }
        for(auto c: tree[p].child){
            if(color[c.first] == 0){
                que.push(c.first);
                dist[c.first] = dist[p]+c.second;
                color[c.first] = 1;
            }
        }
    }
}

int main(){
    Init();
    cin >> n;
    tree.resize(n);

    // 根
    ll root = -1;
    rep(i, n-1){
        // 入力と0-based-index
        ll a, b, c; cin >> a >> b >> c; a--; b--;
        // 両方親が未定の場合
        if(tree[a].parent.first == -1 && tree[b].parent.first == -1){
            tree[b].parent.first = root = a;
            tree[b].parent.second = c;
            tree[a].child.push_back(make_pair(b, c));
        }
        // Aの親が未定の場合
        else if(tree[a].parent.first == -1){
            tree[a].parent.first = b;
            tree[a].parent.second = c;
            tree[b].child.push_back(make_pair(a, c));
        }
        // Bの親が未定の場合
        else{
            tree[b].parent.first = a;
            tree[b].parent.second = c;
            tree[a].child.push_back(make_pair(b, c));
        }
    }

    // クエリの処理
    ll q, k; cin >> q >> k; k--;
    // ノードkから各ノードへの距離
    vector<ll> dist(n);
    bfs(k, dist);

    rep(i, q){
        ll x, y; cin >> x >> y; x--; y--;
        cout << dist[x]+dist[y] << endl;
    }
}
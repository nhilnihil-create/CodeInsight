#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

vector<map<int,int>> children;
vector<int> parent, dist;

void build_tree(int root){
    int n = (int)children.size();
    parent  = vector<int>(n,-1);
    dist    = vector<int>(n,0);
    
    queue<int> q;
    q.push(root);
    
    while(!q.empty()){
        int i = q.front(); q.pop();
        for(auto p : children[i]){
            int to = p.first;
            children[to].erase(i);
            parent[to] = i;
            dist[to]   = dist[i] + p.second;
            q.push(to);
        }
    }
}

void add_node(int a, int b, int c){
    children[a][b] = c;
    children[b][a] = c;
}

signed main(){
    int n; cin >> n;
    children = vector<map<int,int>>(n);
    rep(i,n-1){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        add_node(a, b, c);
    }
    
    int Q, K; cin >> Q >> K;
    build_tree(K-1);
    
    rep(query, Q){
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << dist[x] + dist[y] << endl;
    }
}
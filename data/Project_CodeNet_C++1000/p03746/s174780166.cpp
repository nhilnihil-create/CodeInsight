#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define pye cout << "yes" << endl
#define pno cout << "no" << endl
#define pYe cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pYE cout << "YES" << endl
#define pNO cout << "NO" << endl
#define prin(num) cout << num << endl
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define mp make_pair
#define INF 100000000000
#define MOD 1000000007LL
#define MAX 100005
#define NIL -1
#define WHITE 0
#define BLACK 1
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

class Edge {
public:
    ll t;
    ll w;
    Edge() {}
    Edge(ll t, ll w): t(t), w(w) {}
};

ll N, M;
vector<ll> G[MAX];
vector<ll> ans;
bool visited[MAX];
bool flag;
void dfs(ll u) {
    ans.push_back(u);
    visited[u]=true;
    
    for(ll i=0; i<G[u].size(); i++) {
        ll v=G[u][i];
        if(!visited[v]) {
            dfs(v);
            return;
        }
    }
    return;
}


int main(void) {
    cin >> N >> M;
    ll i;
    ll a, b;
    for(i=0; i<M; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    dfs(1);
    reverse(ans.begin(), ans.end());
    ans.pop_back();
    dfs(1);
    
    prin(ans.size());
    for(i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
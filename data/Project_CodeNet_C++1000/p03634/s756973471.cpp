#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int mod = 1000000007;
const ll inf = 1e18;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

struct edge{
    ll to, cost;
};

vector<vector<edge>> ed;
vector<ll> dis;

int main(){
    ll n;
    cin >> n;
    ed.resize(n);
    rep(i,n-1){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        edge e = {b, c};
        edge f = {a, c};
        ed[a].push_back(e);
        ed[b].push_back(f);
    }
    ll Q, k;
    cin >> Q >> k;
    k--;
    dis.resize(n);
    fill(dis.begin(), dis.end(), inf);
    dis[k] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(P(0, k));
    while(!q.empty()){
        P p = q.top();
        q.pop();
        ll s = p.second;
        if(dis[s] < p.first) continue;
        
        for(int i = 0; i < ed[s].size(); i++){
            edge e = ed[s][i];
            if(dis[e.to] > dis[s] + e.cost){
                dis[e.to] = dis[s] + e.cost;
                q.push(P(dis[e.to], e.to));
            }
        }
    }
    while(Q--){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << dis[a] + dis[b] << endl;
    }
}
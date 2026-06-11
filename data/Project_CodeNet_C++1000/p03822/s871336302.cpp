#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P>IP;
typedef vector<ll> V;
typedef vector<V> V2;
typedef vector<vector<P> > G;
void g_dir(G &graph, ll a, ll b, ll w = 1){graph[a].push_back(P(b, w));}
void g_undir(G &graph, ll a, ll b, ll w = 1){g_dir(graph, a, b, w);g_dir(graph, b, a, w);}
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
const ll INF = 1145141919;
const ll MOD = 1000000007;
const ll NUM = 101010;

priority_queue<P, vector<P>, greater<P> >Q;

ll N, v[NUM], dep[NUM], chi[NUM];

int main(){
    cin >> N;
    for (ll i = 2; i <= N; i++) {
        cin >> v[i];
        chi[v[i]]++;
    }
    for (ll i = 2; i <= N; i++) {
        if (chi[i] == 0) {
            Q.push(P(dep[i], i));
        }
    }
    while(!Q.empty()){
        ll j = Q.top().second;
        Q.pop();
        if (j == 1)break;
        ll i = v[j];
        if (dep[i] <= dep[j])dep[i] = dep[j] + 1;
        else dep[i]++;
        chi[i]--;
        if (chi[i] == 0) {
            Q.push(P(dep[i], i));
        }
        
    }
    cout << dep[1] << endl;
    
    return 0;
}
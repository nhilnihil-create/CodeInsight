#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

struct Node{
    bool visited;
    vector<pair<ll, ll> > par;
    ll depth;
};

Node node[200000];

void dfs(ll index, ll depth){
    node[index].visited=true;
    node[index].depth=depth;
    rep(i, node[index].par.size()){
        if(!node[node[index].par[i].first].visited) dfs(node[index].par[i].first, depth+node[index].par[i].second);
    }
}

int main(void){
    ll N;
    cin>>N;
    rep(i,N) node[i].visited=false;
    rep(i, N-1){
        ll a, b, c;
        cin>>a>>b>>c;
        node[a-1].par.push_back({b-1, c});
        node[b-1].par.push_back({a-1, c});
    }
    ll Q, K;
    cin>>Q>>K;
    dfs(K-1, 0);
    rep(j, Q){
        ll x, y;
        cin>>x>>y;
        cout<<node[x-1].depth+node[y-1].depth<<endl;
    }
            
    return 0;
}

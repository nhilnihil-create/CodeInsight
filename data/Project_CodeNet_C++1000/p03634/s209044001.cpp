#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
vector<vector<pair<ll,ll> > > Graph(100100);
vector<ll>dist(100100);
vector<bool>visited(100100,false);
void dfs(ll from,ll distance){
    dist[from] = distance;
    //cerr << "visit" << from << endl;
    visited[from] = true;
    REP(i,Graph[from].size()){
        if(!visited[Graph[from][i].first]){
            dfs(Graph[from][i].first,distance+Graph[from][i].second);
        }
    }
}

int main(){
    int n;
    cin >> n;
    REP(i,n-1){
        ll a,b,c;
        cin >> a >> b  >>c;
        a--;b--;
        Graph[a].push_back(make_pair(b,c));
        Graph[b].push_back(make_pair(a,c));
    }
    int q,k;

    cin >> q >> k;
    k--;
    vector<ll>x(q),y(q);
    REP(i,q){
        cin >> x[i] >> y[i];
        x[i]--;y[i]--;
    }
    dfs(k,0);
    REP(i,q){
        cout << dist[x[i]]+dist[y[i]] << endl;
    }
    return 0;
}
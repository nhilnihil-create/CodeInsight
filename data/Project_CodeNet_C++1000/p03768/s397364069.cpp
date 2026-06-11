#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int n,m,q;
vector<vector<int> > g;
vector<int> p;
vector<int> res;


int main(){
    cin >> n >> m;
    g.resize(n);
    p.resize(n,-1);
    res.resize(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> q;
    vector<pair<int,pair<int,int> > > query;
    rep(i,q){
        int v,d,c;
        cin >> v >> d >> c;
        v--;
        query.push_back(MP(v,MP(d,c)));
    }
    reverse(query.begin(),query.end());
    rep(i,q){
        int vv = query[i].first;
        int dd = query[i].second.first;
        int c = query[i].second.second;
        queue<pair<int,int> > que;
        que.push(MP(vv,dd));
        while(!que.empty()){
            auto x = que.front();
            que.pop();
            int v = x.first;
            int d = x.second;
            if(p[v]>=d)continue;
            p[v] = d;
            if(res[v]==0)res[v] = c;
            if(d==0)continue;
            for(auto y:g[v]){
                if(p[y]<d-1){
                    que.push(MP(y,d-1));
                }
            }
        }
        
    }
    rep(i,n)cout << res[i] << endl;
    return 0;
}
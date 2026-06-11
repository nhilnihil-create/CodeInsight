//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<pp>> path(n);
    set<pp> se;
    rep(i,m){
        int a,b,c; cin>>a>>b>>c;
        a--; b--;
        path[a].push_back(mk(b,c));
        path[b].push_back(mk(a,c));
        se.insert(mk(a,b));
    }
    rep(i,n){
        int cost,s,to,w;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push(mk(0,i));
        vector<int> d(n,inf);
        d[i]=0;
        while(!(pq.empty())){
            tie(cost,s)=pq.top();
            pq.pop();
            if(d[s]!=cost) continue;
            for(auto p:path[s]){
                tie(to,w)=p;
                if(d[to]>d[s]+w){
                    d[to]=d[s]+w;
                    pq.push(mk(d[to],to));
                }
            }
        }
        queue<int> que;
        que.push(i);
        while(!(que.empty())){
            s=que.front();
            que.pop();
            for(auto p:path[s]){
                tie(to,w)=p;
                if(d[to]-d[s]==w){
                    if(se.count(mk(s,to))) se.erase(mk(s,to));
                    if(se.count(mk(to,s))) se.erase(mk(to,s));
                    que.push(to);
                }
            }
        }
    }
    cout<<se.size()<<endl;
}
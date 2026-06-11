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



int main() {
    int n,m,r,ans=inf,cnt; cin>>n>>m>>r;
    int s,cost;
    vector<int> v(r,0);
    vector<vector<pp>> path(n); 
    vector<vector<int>> dis(n,vector<int>(n,inf));
    rep(i,r){
        cin>>v[i]; v[i]--;
    }
    sort(al(v));
    rep(i,m){
        int a,b,c; cin>>a>>b>>c;
        a--; b--;
        path[a].push_back(mk(b,c));
        path[b].push_back(mk(a,c));
    }
    rep(i,n){
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push(mk(0,i)); dis[i][i]=0;
        while(!(pq.empty())){
            tie(cost,s)=pq.top(); pq.pop();
            if(cost!=dis[i][s]) continue;
            for(auto p : path[s]){
                if(dis[i][p.first]>cost+p.second){
                    dis[i][p.first]=cost+p.second;
                    pq.push(mk(dis[i][p.first],p.first));
                }
            }
        }

    }

    do{
        cnt=0;
        rep(i,r-1){
            cnt+=dis[v[i]][v[i+1]];
        }
        ans=min(ans,cnt);
    }while(next_permutation(al(v)));
    cout<<ans<<endl;
}
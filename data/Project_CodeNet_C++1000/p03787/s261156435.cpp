#include <bits/stdc++.h>
#define REP(i,n) for(LL i=0;i<(LL)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
#define pii pair<LL,LL>
#define pll pair<LL,LL>

using namespace std;

bool used[100001];
bool color[100001];
vector<LL> edge[100001];


LL dfs(LL v,bool cl){
    used[v]=true;
    color[v]=cl;
    LL res=(edge[v].size()>0 ? 1:-1);
    for(LL u:edge[v]){
        if(!used[u])res=max(res,dfs(u,!cl));
        else if(color[u]==cl)res=2;
    }
    return res;
}

int main(){

    LL N,M;cin>>N>>M;

    REP(i,M){
        LL u,v;cin>>u>>v;
        edge[--u].push_back(--v);
        edge[v].push_back(u);
    }
    fill_n(used,N,false);
    LL ans=0;
    LL p=0,q=0,r=0;
    REP(i,N)if(!used[i]){
            switch(dfs(i,true)){
                case -1:
                    r++;
                    break;
                case 1:
                    q++;
                    break;
                case 2:
                    p++;
                    break;
            }
        }
    ans = 2*N*r-r*r +p*p+2*p*q+2*q*q;
    cout<<ans<<endl;



    return 0;
}
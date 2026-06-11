#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp(a,b) make_pair(a,b)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;
vector<int> G[300000];
int64_t dist[100001];
bool visited[100001];
map<pair<int,int>,int64_t> p;
void dfs(int k){//地点kから距離を探索
    visited[k]=true;
    rep(i,G[k].size()){//kの隣接点を探索
        int next = G[k][i];
        if(!visited[next]){//まだ探索してない
            visited[next]=true;
            dist[next] = dist[k] + p[mp(next,k)];
            dfs(next);
        }
    }
}
int main(){
    int n;
    cin>>n;
   vector<int> a(n),b(n),c(n);
    rep(i,n-1){
        cin >> a[i]>>b[i]>>c[i];
        a[i]--,b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
        p[mp(a[i],b[i])]=c[i];
        p[mp(b[i],a[i])]=c[i];
    }
    rep(i,n){
        visited[i]=false;
    }
    int q,k;
    cin>>q>>k;
    k--;
    dist[k]=0;
    dfs(k);
    rep(i,q){
        int x,y;
        cin>>x>>y;
        x--,y--;
        cout<<dist[x]+dist[y]<<endl;
    }
}
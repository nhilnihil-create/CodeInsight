#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999999;

void dfs(vector<ll> &distance, int now, vector<vector<P> > &G){
    //cout<<"debug"<<endl;
    for(P p:G[now]){
        int to=p.first;
        ll cost=p.second;
        if(distance[to]!=INF) continue;
        distance[to]=distance[now]+cost;
        dfs(distance,to,G);
    }
    return ;
}


int main(){
    int n;
    cin>>n;
    vector<vector<P> > G(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        ll c; 
        cin>>c;
        a--; b--;
        G[a].push_back(P(b,c));
        G[b].push_back(P(a,c));
    }
    int q,k;
    cin>>q>>k;
    k--;
    vector<ll> distance(n);
    for(int i=0;i<n;i++) distance[i]=INF;
    distance[k]=0;
    dfs(distance, k, G);
    vector<ll> ans(q);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        ans[i]=distance[a]+distance[b];
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
    
}
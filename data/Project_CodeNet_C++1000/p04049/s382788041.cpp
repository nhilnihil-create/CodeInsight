#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>
 
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> P;
 
#define all(x) x.begin(),x.end()
 
const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;
 
int n,k,cnt;
vector<int> flag;
vector<vector<P> > g;
vector<P> edge;


void delete_count(int x,int len,int lim){
    flag[x] = 1;
    if(len > lim) cnt++;
    for(int i = 0; i < g[x].size(); i++){
        int now = g[x][i].second;
        if(flag[now]<0) delete_count(now,len+1,lim);
    }
}
 
int main()
{
    cin>>n>>k;
    g.resize(n);
    flag.resize(n);
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].push_back(P(1,b));
        g[b].push_back(P(1,a));
        edge.push_back(P(a,b));
    }
 

    int ans = INF;
    if(k%2==0){
        for(int i = 0; i < n; i++){
            flag.assign(flag.size(),-1);
            cnt = 0;
            delete_count(i,0,k/2);
            ans = min(ans,cnt);
        }
    }else{
        for(int i = 0; i < edge.size(); i++){
            int x = edge[i].first,y = edge[i].second;
            flag.assign(flag.size(),-1);
            cnt = 0;
            flag[x]=1;
            flag[y]=1;
            delete_count(x,0,(k-1)/2);
            delete_count(y,0,(k-1)/2);
            ans = min(ans,cnt);
        }
    }

    cout << ans << endl;
 
    return 0;
}
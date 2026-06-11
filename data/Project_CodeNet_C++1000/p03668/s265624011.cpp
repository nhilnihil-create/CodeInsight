#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a,const T &b){
    if(a>b)return false;
    a=b;
    return true;
}
template<class T>bool chmin(T &a,const T &b){
    if(a<b)return false;
    a=b;
    return true;
}

/*-------------------------------------------*/

int n,x,y;
vector<int> e[100009];
bool visited[100009];

int dfs(int m){
    visited[m]=true;
    int re=0,cnt=0;
    rep(i,e[m].size()){
        if(!visited[e[m][i]]){
            cnt++;
            re^=dfs(e[m][i])+1;
        }
    }
    return re;
}

int main(){
    cin>>n;
    rep(i,n-1){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    cout<<(dfs(1)?"Alice\n":"Bob\n");
}
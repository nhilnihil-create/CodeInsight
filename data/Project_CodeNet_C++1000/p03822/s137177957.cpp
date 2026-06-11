#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int N;
vector<vector<int>> G(100000);

void dfs(int n,vector<int> &count){
    if (G[n].size()==0){
        count[n]=0;
        return;
    }
    if (G[n].size()==1){
      	dfs(G[n][0],count);
        count[n]=count[G[n][0]]+1;
        return;
    }
    priority_queue<int> pq1,pq2;
    for(auto x:G[n]){
        dfs(x,count);
        pq1.push(count[x]);
    }
    int i=1;
    while(!pq1.empty()){
        int x=pq1.top();
        pq1.pop();
        pq2.push(x+i);
        i++;
    }
    count[n]=pq2.top();
    return;
}

int main(){
    cin >> N;
    rep(i,N-1){
        int a;
        cin >> a;
        a--;
        G[a].push_back(i+1);
    }
    vector<int> count(N);
    dfs(0,count);
    cout << count[0] << endl;
}
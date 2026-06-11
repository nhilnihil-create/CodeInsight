#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int N;ll W;cin>>N>>W;
    vector<vector<ll>> knapsack(4);
    ll v;ll w;
    ll w1;
    REP(i,N){
        cin>>w>>v;
        if(i==0)w1=w;
        knapsack[(int)(w-w1)].push_back(v);
    }
    REP(i,4)sort(all(knapsack[i]),greater<ll>());
    REP(i,4)FOR(j,1,knapsack[i].size())knapsack[i][j]+=knapsack[i][j-1];
    vector<int> n(4);
    ll res=0;
    REP(i,4)n[i]=knapsack[i].size();
    REP(i,n[0]+1)REP(j,n[1]+1)REP(k,n[2]+1)REP(l,n[3]+1){
        if(i*w1+j*(w1+1)+k*(w1+2)+l*(w1+3)>W)continue;
        ll tmp=0;
        if(i>0)tmp+=knapsack[0][i-1];
        if(j>0)tmp+=knapsack[1][j-1];
        if(k>0)tmp+=knapsack[2][k-1];
        if(l>0)tmp+=knapsack[3][l-1];
        res=max(res,tmp);
    }
    cout<<res<<endl;
    return 0;
}
#include <iostream>
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
ll n,m,r,a,b,c,dp[1000],INF=(1LL<<60);
vector<PP> v;
bool Bell(void){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dp[v[j].F.F]!=INF&&dp[v[j].F.S]>dp[v[j].F.F]+v[j].S){
                dp[v[j].F.S]=dp[v[j].F.F]+v[j].S;
                if(i==n-1&&v[j].F.S==n-1)return false;
            }
        }
    }
    return true;
}
int main(void){
    cin>>n>>m;
    for(int i=0;i<1000;i++)dp[i]=INF;
    dp[0]=0;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        a--,b--,c*=-1;
        v.push_back({{a,b},c});
    }
    if(!Bell()){
        cout<<"inf"<<endl;
        return 0;
    }
    cout<<-dp[n-1]<<endl;
}

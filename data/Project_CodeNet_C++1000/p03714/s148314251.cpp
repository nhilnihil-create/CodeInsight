#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int n; cin>>n;
    long long a[3*n]; rep(i,3*n) cin>>a[i];
    long long sumL[n+1]={},sumR[n+1]={};
    priority_queue<long long,vector<long long>,greater<long long>> pqL;
    rep(i,n){
        pqL.push(a[i]);
        sumL[0]+=a[i];
    }
    for(int i=1;i<n+1;i++){
        pqL.push(a[n-1+i]);
        long long sub=pqL.top(); pqL.pop();
        sumL[i]=sumL[i-1]+a[n-1+i]-sub;
    }
    priority_queue<long long,vector<long long>> pqR;
    reverse(a,a+3*n);
    rep(i,n){
        pqR.push(a[i]);
        sumR[0]+=a[i];
    }
    for(int i=1;i<n+1;i++){
        pqR.push(a[n-1+i]);
        long long sub=pqR.top(); pqR.pop();
        sumR[i]=sumR[i-1]+a[n-1+i]-sub;
    }
    reverse(sumR,sumR+n+1);
    long long ans=-LINF;
    rep(i,n+1){
        // cout<<sumL[i]<<" "<<sumR[i]<<endl;
        ans=max(ans,sumL[i]-sumR[i]);
    }
    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const int INF=1e18;
const int MOD=1e9+7;

signed main(){
    int n;cin>>n;
    int a[3*n];
    REP(i,3*n)cin>>a[i];
    vector<int> plus(3*n,0);
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int> minus(3*n,0);
    priority_queue<int>mq;
    for(int i=0;i<n;i++){
        plus[n-1]+=a[i];
        pq.push(a[i]);
    }
    for(int i=2*n;i<3*n;i++){
        minus[2*n]+=a[i];
        mq.push(a[i]);
    }
    for(int i=n;i<2*n;i++){
        pq.push(a[i]);
        plus[i]=plus[i-1]+a[i]-pq.top();
        pq.pop();
    }   
    for(int i=2*n-1;i>=n;i--){
        mq.push(a[i]);
        minus[i]=minus[i+1]+a[i]-mq.top();
        mq.pop();
    }
    int ans=-INF;
    for(int i=n-1;i<2*n;i++) chmax(ans,plus[i]-minus[i+1]);
    cout<<ans<<endl;
}
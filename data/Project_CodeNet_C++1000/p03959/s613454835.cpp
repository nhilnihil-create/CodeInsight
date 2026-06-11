 #include "bits/stdc++.h"

using namespace std;

#define sp(x) cout<<setprecision(x);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(), (a).end()
#define inf 10000000
#define linf INT64_MAX*0.99
#define print(s) cout<<(s)<<endl
#define lint long long
#define yes "Yes"
#define no "No"

typedef pair<int, int> P;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<int> a(n),t(n);
    vector<lint> ans(n,-1); 
    REP(i,n) cin>>t[i];
    ans[0] = 1; ans[n-1] = 1;
    REP(i,n) cin>>a[i];
    REP(i,n-1){
        if(t[i]!=t[i+1]){
            ans[i+1] = 1;
            if(a[i+1]<t[i+1]) ans[i+1]=0; 
        } 
        else if(a[i]!= a[i+1]){
            ans[i] = 1;
            if(a[i]>t[i]) ans[i]=0;
        } 
    }
    lint cnt = 1;
    REP(i,n){
        if(ans[i]==-1) ans[i] = min(a[i],t[i]);
        cnt*=ans[i];
        cnt%=1000000007;
    }
    if(t[n-1]!=a[0]) cnt= 0;
    print(cnt);
    return 0;
}
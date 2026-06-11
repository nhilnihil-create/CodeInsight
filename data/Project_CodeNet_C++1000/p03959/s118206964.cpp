#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    vector<int> A(N),B(N);
    rep(i,0,N)cin >> A[i];
    rep(i,0,N)cin >> B[i];
    vector<int> upA(N),upB(N);
    upA[0] = upB[N-1] = 1;
    rep(i,1,N)if(A[i] > A[i-1])upA[i] = 1;
    for(int i = N-2;i >= 0;i--)if(B[i] > B[i+1])upB[i] = 1;
    ll ans = 1;
    //rep(i,0,N)cout << upA[i] << " ";cout<< endl;
    //rep(i,0,N)cout << upB[i] << " ";cout  << endl;
    rep(i,0,N){
        //if(upA[i] && upB[i] && A[i] != B[i])ans = 0;
        if(upA[i] && A[i] > B[i])ans = 0;
        if(upB[i] && B[i] > A[i])ans = 0;
        if(!(upA[i] || upB[i]) )ans *= min(A[i], B[i]);
        ans %= MOD;
        //cout << ans << endl;
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<ll> A(N),B(N);
    rep(i,N){
        cin >> A[i] >> B[i];
    }
    ll cnt = 0;
    for(int i=N-1;i>=0;i--){
        ll tmp = (A[i]+cnt)%B[i];
        if(tmp==0) continue;
        cnt += B[i] - tmp; 
    }
    cout << cnt << endl;
    return 0;
}
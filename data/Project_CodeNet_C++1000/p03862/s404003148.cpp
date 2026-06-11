#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,X;
    cin >> N >> X;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    // 左端から貪欲法
    ll ans = 0;
    if(A[0]>X){
        ans += A[0] - X;
        A[0] = X;
    }
    for(int i=1;i<N;i++){
        if(A[i-1]+A[i]>X){
            ans += A[i-1]+A[i]-X;
            A[i] = X - A[i-1];
        }
    }
    cout << ans << endl;
    return 0;
}

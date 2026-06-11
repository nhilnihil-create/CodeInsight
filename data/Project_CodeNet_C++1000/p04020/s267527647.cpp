#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    ll ans = 0;
    rep(i,N){
        if(i!=N-1){
            ans+=A[i]/2;
            if(A[i+1]!=0&&A[i]%2==1){
                A[i+1]-=1;
                ans++;
            }
        }else{
            ans += A[i]/2;
        }
    }
    cout << ans << endl;
    return 0;
}
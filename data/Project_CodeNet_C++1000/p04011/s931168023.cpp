#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,K,X,Y;
    cin >> N >> K >> X >> Y;
    int ans = 0;
    rep(i,N){
        if(i+1<=K){
            ans += X;
        }else{
            ans += Y;
        }
    }
    cout << ans << endl;
    return 0;
}
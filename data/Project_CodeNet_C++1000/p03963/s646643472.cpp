#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N,K;
    cin >> N >> K;
    
    ll ans;
    ans=K;
    
    for(int i=2; i<=N; i++){
        ans *= K-1;
    }
    
    cout << ans << endl;
}

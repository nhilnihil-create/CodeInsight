#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,M;
    cin >> N >> M;
    ll ans = 0;
    if (N * 2 > M){
        ans += M / 2;
    }
    else{
        M -= N * 2;
        ans += N;
        ans += M / 4;
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
    LL N,K; cin >> N >> K;
    LL ans;
    ans = K*pow(K-1,N-1);

    cout << ans << endl;
}
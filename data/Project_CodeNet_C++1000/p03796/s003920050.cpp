#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9+7;

int main(){

    int N;
    cin >> N;

    ll ans = 1;
    for (int i=1; i<=N; i++){
        ans *= i;
        ans %= INF; 
    }

    cout << ans << endl;
    return 0;
}
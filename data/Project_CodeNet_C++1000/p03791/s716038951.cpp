#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9+7;

int main(){
    int N;
    cin >> N;
    vector<int> x(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    x[0] = 1;
    ll ans = 1;
    int cnt = 1;
    for (int i = 1; i < N; i++) {
        ans = ans*(cnt+1)%mod;
        if (x[i] >= x[i-1]+2) {
            x[i] = x[i-1]+2;
            cnt++;
        }else x[i] = x[i-1];
    }
    cout << ans << endl;
    return 0;
}
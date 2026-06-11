#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = 0;
    ll price = 1;
    for (int i = 0; i < N; i++) {
        if (A[i] < price) continue;
        if (A[i] == price) {
            price++;
            continue;
        }
        ans += (A[i]-1)/price;
        if (price==1) price++;
    }
    cout << ans << endl;
    return 0;
}
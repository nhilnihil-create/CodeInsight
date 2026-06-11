#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main(){
    int N, K;
    cin >> N >> K;
    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    ll sum[N];
    ll sumOfPlus[N];
    sum[0] = a[0];
    sumOfPlus[0] = max(0, a[0]);
    for(int i = 1; i < N; i++){
        sum[i] = sum[i-1] + a[i];
        sumOfPlus[i] = sumOfPlus[i-1] + max(0, a[i]);
    }

    ll ans = sum[K-1] + sumOfPlus[N-1] - sumOfPlus[K-1];
    ans = max(ans, sumOfPlus[N-1] - sumOfPlus[K-1]);
    for(int i = 1; i <= N-K; i++){
        ans = max(ans, sum[i+K-1] - sum[i-1] + sumOfPlus[N-1] - sumOfPlus[i+K-1] + sumOfPlus[i-1]);
        ans = max(ans, sumOfPlus[N-1] - sumOfPlus[i+K-1] + sumOfPlus[i-1]);
    }

    cout << ans << "\n";
    return 0;
}
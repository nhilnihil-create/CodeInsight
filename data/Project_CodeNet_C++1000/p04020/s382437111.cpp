#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;

int main() {
    ll N; cin >> N;
    ll A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    ll ans = 0;
    ans += A[0]/2;
    A[0] = A[0]%2;
    for (int i = 1; i < N; i++)
    {
        if(A[i] == 0) continue;
        A[i] += A[i-1];
        ans += A[i]/2;
        A[i] = A[i]%2;
    }
    cout << ans << endl;
}
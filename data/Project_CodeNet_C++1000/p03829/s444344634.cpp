#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

ll arr[100000];
int main() {
    cin >> N >> A >> B;
    rep(i, N){
        cin >> arr[i];
    }
    ll sum = 0;
    rep(i, N-1){
        sum += min(B, A*(arr[i+1] - arr[i]));
    }
    cout << sum;
}

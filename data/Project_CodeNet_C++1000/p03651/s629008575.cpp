#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int MOD = 1000000007;

ll gcd(ll a, ll b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(void){
    int N, K; cin >> N >> K;
    vector<int> A(N); for(int i = 0; i < N; i++) cin >> A[i];
    
    int g = 0;
    int max_A = 0;
    for(int i = 0; i < N; i++){
        g = __gcd(g, A[i]);
        max_A = max(max_A, A[i]);
    }
    
    if (K % g == 0 && K <= max_A) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}

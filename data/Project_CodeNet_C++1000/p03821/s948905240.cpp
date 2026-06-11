#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;


int main(){
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    ll total = 0;
    for(int i = N - 1; i >= 0; i--){
        A[i] += total;
        if(A[i] % B[i] != 0) {
            total += B[i] - (A[i] % B[i]);
        }
    }
    cout << total << endl;
    return 0;
}

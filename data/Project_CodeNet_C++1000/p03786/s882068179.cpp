#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i=0;i<N;i++) cin >> A[i];
    sort(A.begin(),A.end());
    ll sum = 0;
    ll last = -1;
    for (int i=0;i<N-1;i++){
        sum += A[i];
        if (A[i+1] > 2*sum) {
            last = i;
        }
    }
    cout << N - last - 1 << "\n";
}
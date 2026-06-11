#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N){
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    vector<ll> B(N);
    B[0] = A[0];
    for (int i = 1; i < N; i++){
        B[i] = B[i-1] + A[i];
    }

    int num = 0;
    for (int i = 0; i < N-1; i++){
        if(B[i] * 2 < A[i+1])num = i+1;
    }

    cout << N - num << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    int M;
    M = (int)log10(N)+ 1;
    int A, B, m;
    for(ll i = 1; i*i <= N; i++){
        if(N % i != 0) continue;
        m = 0;
        A = (int)log10(i) + 1;
        B = (int)log10(N / i) + 1;
        m = max(A, B);
        M = min(M, m);
    }
    cout << M << endl;
}
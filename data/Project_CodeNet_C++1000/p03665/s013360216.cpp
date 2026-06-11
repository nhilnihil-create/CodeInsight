#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, P; cin >> N >> P;
    long long A[N];
    long long odd = 0, even = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if(A[i] % 2 == 1) odd++;
    }

    long long ans = 0;
    if(odd == 0){
        if(P == 0) ans = 1LL<<N;
        else ans = 0;
    }
    else ans = 1LL<<(N-1);
    cout << ans << endl;
}
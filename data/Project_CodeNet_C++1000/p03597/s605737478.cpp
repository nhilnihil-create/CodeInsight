#include <iostream>
using namespace std;

void solve(long long N, long long A){
    cout << N * N - A << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long N;
    scanf("%lld",&N);
    long long A;
    scanf("%lld",&A);
    solve(N, A);
    return 0;
}

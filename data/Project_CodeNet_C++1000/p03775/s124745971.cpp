#include <bits/stdc++.h>
using namespace std;
const long long INF = (1<<29);


long long calc_digit(long long N){
    long long res = 0;
    while(N){
        res++;
        N /= 10;
    }
    return res;
}

void solve(long long N){
    long long ans = INF;
    for(long long A = 1; A * A <= N; A++){
        if(N % A == 0){
            long long B = N / A;
            long long F = max(calc_digit(A), calc_digit(B));
            ans = min(ans, F);
        }
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}

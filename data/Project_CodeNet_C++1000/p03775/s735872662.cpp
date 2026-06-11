#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;

long long calc_digit(long long N){
    long long ans = 0;
    while(N>0){
        N /= 10;
        ans++;
    }
    return ans;
}

int main(){
    long long N;
    cin >> N;
    long long ans = INF;
    for(long long A = 1; A*A <= N; A++ ){
        if(N%A!=0)continue;
        long long B = N / A;
        long long res = max(calc_digit(A),calc_digit(B));
        ans = min(ans,res);
    }
    cout << ans << endl;
    return 0;
}

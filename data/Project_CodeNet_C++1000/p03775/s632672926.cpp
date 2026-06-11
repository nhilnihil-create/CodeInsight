#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;

int calc_digit(long long N){
    int res = 0;
    while(N > 0){
        res++;
        N /= 10;
    }
    return res;
}

int main(){
    long long N; cin >> N;
    long long res = INF;
    for(long long a = 1; a*a<= N ; a++){
        if(N%a!=0)continue;
        long long b = N/a;
        long long tmp = max(calc_digit(a),calc_digit(b));
        res = min(res,tmp);
    }
    cout << res << endl;
}
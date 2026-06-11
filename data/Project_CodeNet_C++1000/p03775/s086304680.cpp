#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

long long F(long long A, long  long B){
    long long ta = A, tb = B;
    long long ca = 0, cb = 0;
    for(long long i = 0; i < 10; i++){
        if(ta != 0) ca++;
        if(tb != 0) cb++;
        ta /= 10;
        tb /= 10;
    }
    return ca > cb ? ca : cb;
}

int main() {
    long long  N;
    cin >> N;
    long long ans = 10;
    for(long long i = 1; i <= sqrt(N); i++){
        if(N % i == 0) {
            ans = min(ans, F(i, N/i));
        }
    }
    cout << ans << endl;
}






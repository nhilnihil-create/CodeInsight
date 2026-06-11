#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long N,T;
    cin >> N >> T;
    vector<long long> t(N);
    for(long long i = 0; i < N; i++) cin >> t[i];
    long long D = T;
    for(long long i = 1; i < N; i++){
        long long d = t[i] - t[i-1];
        if(d <= T) D += d;
        else D += T;
    }
    cout << D << endl;
}
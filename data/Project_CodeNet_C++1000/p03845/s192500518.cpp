#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long t[n];
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        cin >> t[i];
        sum += t[i];
    }
    long long m;
    cin >> m;
    long long ans[m];

    for(long long i = 0; i < m; i++){
        long long p, x;
        cin >> p >> x;
        p--;
        ans[i] = sum + x - t[p];
    }

    for(long long i = 0; i < m; i++){
        printf("%lld\n", ans[i]);
    }
    return 0;
}
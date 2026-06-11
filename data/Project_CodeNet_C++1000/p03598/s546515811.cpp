#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;

    long long x[n];

    for(long long i = 0; i < n; i++) cin >> x[i];

    long long ans = 0;
    for(long long i = 0; i < n; i++){
        ans += min(abs(x[i]), abs(x[i]-k));
    }
    cout << 2 * ans << endl;
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long ans = 0;
    for(long long i = 0; i < n; i++){
        long long l, r;
        cin >> l >> r;
        ans += r - l + 1;
    }
    cout << ans << endl;
    return 0;
}
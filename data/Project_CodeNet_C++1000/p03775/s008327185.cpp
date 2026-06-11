/**
 *    author:  FromDihPout
 *    created: 2020-06-26
**/

#include <bits/stdc++.h>
using namespace std;


int digits(int n) {
    int cnt = 0;
    while (n > 0) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n;
    cin >> n;
    
    for (int i = floor(sqrt(n)); i >= 1; i--) {
        if (n % i == 0) {
            cout << digits(n / i) << endl;
            break;
        }
    }
    return 0;
}
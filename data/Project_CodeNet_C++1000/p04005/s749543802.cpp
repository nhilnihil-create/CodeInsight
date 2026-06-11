#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int a[3];
    cin >> a[0] >> a[1] >> a[2];
    if(a[0]%2 == 0 || a[1]%2 == 0 || a[2]%2 == 0) {
        cout << 0 << '\n';
    } else {
        sort(a, a+3);
        cout << ((a[2] - a[2]/2)*a[1]*a[0] - (a[2]/2)*a[1]*a[0]) << '\n';
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long k;
long long a[50];
int main() {
    cin >> k;
    /*if (k == 0) {
        cout << 1 << '\n';
        cout << 0;
        return 0;
    }*/
    //x + n ... x + n - a
    //x ... x - b
    //2n - a - 1  a
    //n - a - 1 b
    //a + n * (x - (n - a - 1)) = k;
    cout << 50 << '\n';
    long long a = (k % 50);
    long long x = (k / 50) + (50 - a - 1);
    for (int i = 0; i < a; i++) {
        cout << x + 50 << " ";
        //a[i] = x + 50;
    }
    for (int i = a; i < 50; i++) {
        cout << x << " ";
        //a[i] = x;
    }
    return 0;
}

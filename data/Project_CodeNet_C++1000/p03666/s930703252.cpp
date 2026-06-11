#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    b -= a;

    bool f = false;
    for(int i=0; i<n; i++) {
        long r1 = -i*c + (n-1-i)*d;
        long r2 = (n-1-i)*c - i*d;

        if(r1 <= b && b <= r2) f = true;
        if(r2 <= b && b <= r1) f = true;
    }
    cout << (f ? "YES" : "NO") << endl;
}

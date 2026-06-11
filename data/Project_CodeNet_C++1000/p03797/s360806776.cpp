#include<bits/stdc++.h>
using namespace std;
long inf = 1000000007;

int main() {
    long n, m; cin >> n >> m;
    long count = 0;

    if (m >= 2 * n) {
        count += n;
        /*n = 0;*/
        m -= 2 * n;
        cout << count + m / 4 << endl;
    }
    else {
        count += m / 2;
        n -= m / 2;
        m -= (m / 2) * 2;
        cout << count << endl;
    }
}


    

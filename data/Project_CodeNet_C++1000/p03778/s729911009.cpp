#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int W, a, b;
    cin >> W >> a >> b;

    if(b < a) swap(a, b);

    if(a + W >= b) {
        cout << 0 << endl;
        return 0;
    }

    cout << b - a - W << endl;
}
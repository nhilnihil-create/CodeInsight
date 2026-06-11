#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string a, b, c;
    cin >> a >> b >> c;

    if(a[a.length() - 1] == b[0] && b[b.length() - 1] == c[0]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
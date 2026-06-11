#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<ll, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int x, y, a = 0, b = 0;
    cin >> x >> y;

    if(x != 2) {
        if(x == 4 || x == 6 || x == 9 || x == 11) a++;
        else b++;
    }
    if(y != 2) {
        if(y == 4 || y == 6 || y == 9 || y == 11) a++;
        else b++;
    }

    if(a == 2 || b == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
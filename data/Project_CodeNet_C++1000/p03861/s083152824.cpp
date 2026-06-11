#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll a, b, x;
    cin >> a >> b >> x;

    if(a == 0)
        a -= x;
    else a--;

    cout << b / x - a / x << endl;
}
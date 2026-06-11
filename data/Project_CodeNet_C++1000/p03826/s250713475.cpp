#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << max(a * b, c * d) << endl;
}
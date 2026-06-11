#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
int a,b,c;
cin >> a >> b >> c;
if (a == b && b == c) cout << 1 << endl;
else if (a == b || b == c || a == c) cout << 2 << endl;
else cout << 3 << endl;

return 0;
}
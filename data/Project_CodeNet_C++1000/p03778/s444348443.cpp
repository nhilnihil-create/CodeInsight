#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main() {
int W,a,b;
cin >> W >> a >> b;
if (abs(b-a) <= W) cout << 0 << endl;
else {
    if (b > a) cout << b-(a+W) << endl;
    else cout << a-(b+W) << endl;
}


return 0;
}
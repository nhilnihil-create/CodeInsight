#include<bits/stdc++.h>
using namespace std;
#define int long
using pi=pair<int,int>;
signed main(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    b = abs(a - b), --n;
    for (int x = 0; x <= n;++x)
        if (c * (n - x) - d * x <= b && b <= d * (n - x) - c * x) return cout << "YES", 0;
    cout << "NO";
}
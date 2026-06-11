#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int a,b,c,d,x,y;
    cin >> a >> b >> c >>d;

    x = min(b,d);
    y = max(a,c);
    
    if(x-y>0) cout << x-y << endl;
    else cout << 0 << endl;

    return 0;
}
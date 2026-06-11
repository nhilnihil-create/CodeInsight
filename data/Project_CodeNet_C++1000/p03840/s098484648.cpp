#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    cout << max((a/2)*2+(d/2)*2+(e/2)*2, ((a-1)/2)*2+((d-1)/2)*2+((e-1)/2)*2 + (a > 0 && d > 0 && e > 0 ? 3 : 0))+b << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, x, y, t, ans = 0; 
    cin >> n >> x;
    x = min(x, n-x);
    y = n-x;
    while (x != 0)
    {
        ans += (y / x) * x * 3;
        t = x;
        x = y % x;
        y = t;
    }
    cout << ans << endl;
}
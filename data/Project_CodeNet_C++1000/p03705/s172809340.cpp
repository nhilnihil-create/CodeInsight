#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, a, b, ans;
    cin >> n >> a >> b;
    
    if(b<a || (n == 1 && a != b)) ans = 0;
    else ans = (n-2) * (b - a) + 1;

    cout << ans << endl;

    return 0;
}
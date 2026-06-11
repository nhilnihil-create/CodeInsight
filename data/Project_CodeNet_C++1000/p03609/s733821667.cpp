#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    int res = a-b;
    if(res < 0) cout << 0 << endl;
    else cout << res << endl;
    return 0;
}
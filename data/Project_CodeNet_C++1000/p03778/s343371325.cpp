#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int w,a,b;
    cin >> w >> a >> b;

    if(max(a,b)-min(a,b)<w) cout << 0 << endl;
    else cout << max(a,b)-min(a,b)-w << endl;

    return 0;
}
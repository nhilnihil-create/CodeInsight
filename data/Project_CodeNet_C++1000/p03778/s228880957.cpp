#include <bits/stdc++.h>
using namespace std;

int main()
{
    int  w, a, b; cin >> w >> a >> b;

    int ans;

    if (a + w < b) {
        ans = b - (a + w);
    }
    else if (b + w < a){
        ans = a - (b + w);
    }
    else {
        ans = 0;
    }

    cout << ans << endl;

    return 0;
}
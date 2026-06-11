#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int a,b,c,d,start,end,ans;
    cin >> a >> b >> c >> d;
    start = max(a,c);
    end = min(b,d);

    ans = end-start;

    if(end-start < 0) ans = 0;

    cout << ans << endl;

    return 0;
}
#include<bits/stdc++.h>
typedef long long int lld;
using namespace std;

int main()
{
    lld a, b, x, cnt = 0, start, last;
    cin >> a >> b >> x;

    start = a/x;
    last = b/x;

    cnt = last - start;
    if(a % x == 0)cnt++;

    cout << cnt;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long llmin(long long a, long long b){return a > b ? b : a;}

int main()
{
    long long q,h,s,d,n;
    cin >> q >> h >> s >> d >> n;

    long long ans = n / 2 * llmin(q * 8, min(h * 4, min(s * 2, d)));
    n %= 2;
    ans += n * llmin(q * 4, llmin(h * 2, s));

    cout<< ans << endl;
}

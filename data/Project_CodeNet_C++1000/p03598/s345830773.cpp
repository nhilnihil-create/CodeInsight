#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, x, a, b;
    int ans = 0;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        //パターンA
        a = x * 2;
        //パターンB
        b = (K - x);
        if (b < 0)
        {
            b *= -1;
        }
        b = b * 2;
        
        if (a < b)
        {
            ans += a;
        }
        else
        {
            ans += b;
        }
    }
    cout << ans << endl;
}
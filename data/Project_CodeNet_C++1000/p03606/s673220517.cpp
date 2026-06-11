#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, l, r, a;
    int ans = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> l >> r;
        a = l - r;
        if(a == 0 || a > 0)
        {
            a++;
        }
        else
        {
            a = a * -1 + 1;
        }
        ans += a;
    }
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N, x;
    cin >> N >> x;

    vector<long long> a(N);
    for (long long i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    long long ans = 0;
    for (long long i = 1; i < N; i++)
    {
        if (a[i-1] + a[i] > x)
        {
            ans += a[i-1] + a[i] - x;
            if (a[i] > a[i-1] + a[i] - x)
            {
                a[i] -= a[i-1] + a[i] - x;
            }
            else
            {
                a[i] = 0;
            }
        }
    }
    cout << ans << endl;
}
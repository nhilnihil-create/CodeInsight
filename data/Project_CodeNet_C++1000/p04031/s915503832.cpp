#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;

    cin >> N;

    vector<int> a(N,0);
    int ans = 4000000;

    for(int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    for(int i = -100; i <= 100; ++i)
    {
        int tmp = 0;
        for(int j = 0; j < N; ++j)
        {
            tmp += pow(a[j]-i, 2);
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}


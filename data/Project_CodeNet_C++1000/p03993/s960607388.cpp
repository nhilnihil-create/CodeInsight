#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int N;
    int cnt = 0;
    cin >> N;
    vector<int> a(N);
    rep(i, 0, N)
    {
        cin >> a[i];
    }
    rep(i, 0, N)
    {
        if (i == a[a[i] - 1] - 1)
        {
            cnt++;
        }
    }

    cout << cnt / 2 << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int ans[2 * MAXN - 1];
bool reserved[2 * MAXN];

int main()
{
    int n, x;
    cin >> n >> x;
    if (x == 1 || x == 2 * n - 1)
    {
        cout << "No" << endl;
    }
    else if (n == 2)
    {
        cout << "Yes" << endl;
        cout << 1 << endl;
        cout << 2 << endl;
        cout << 3 << endl;
    }
    else
    {
        int mid = (2 * n - 1) / 2;
        ans[mid] = x;
        if (x == 2)
        {
            ans[mid + 1] = 1;
            ans[mid + 2] = 3;
            ans[mid - 1] = 4;
            reserved[1] = reserved[2] = reserved[3] = reserved[4] = true;
        }
        else
        {
            ans[mid + 1] = x + 1;
            ans[mid + 2] = x - 1;
            ans[mid - 1] = x - 2;
            reserved[x - 2] = reserved[x - 1] = reserved[x] = reserved[x + 1] = true;
        }
        int cnt = 1;
        for (int i = 0; i < 2 * n - 1; i++)
        {
            if (ans[i] != 0)
                continue;
            while (reserved[cnt])
                cnt++;
            ans[i] = cnt++;
        }
        cout << "Yes" << endl;
        for (int i = 0; i < 2 * n - 1; i++)
            cout << ans[i] << endl;
    }
    return 0;
}

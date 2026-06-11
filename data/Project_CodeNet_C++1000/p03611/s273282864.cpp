#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    int ans = 0;
    vector<int> count(110000, 0);
    for (int i = 0; i < N; ++i)
    {
        ++count[a[i]];
    }

    for (int i = 0; i < 110000; ++i)
    {
        if (i == 0)
        {
            ans = max(ans, count[i] + count[i + 1]);
        }
        else if (i == 1)
        {
            ans = max(ans, count[i] + count[i - 1]);
        }
        else
        {
            ans = max(ans, count[i] + count[i - 1] + count[i - 2]);
        }
    }

    cout << ans << endl;
}
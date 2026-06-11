#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MAXA = 1E9;
int a[MAXN];
long long ans[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<pair<int, int>> important;
    int most = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > most)
        {
            most = a[i];
            important.push_back({i, most});
        }
    }
    sort(a, a + n);
    int ptr = n - 1;
    while (ptr >= 0)
    {
        int ind = important[(int) important.size() - 1].first;
        important.pop_back();
        int target = important.empty() ? 0 : important[(int) important.size() - 1].second;
        while (ptr >= 0 && a[ptr] > target)
        {
            int start = ptr;
            while (ptr - 1 >= 0 && a[ptr - 1] == a[start])
                ptr--;
            int next = ptr - 1 >= 0 ? a[ptr - 1] : 0;
            ans[ind] += (long long) (n - ptr) * (a[start] - next);
            ptr--;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
    return 0;
}

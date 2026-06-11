#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long s = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] - a[i - 1] <= t)
            s += a[i] - a[i - 1];
        if (a[i] - a[i - 1] > t)
            s += t;
    }
    s += t;
    cout << s;
    return 0;
}

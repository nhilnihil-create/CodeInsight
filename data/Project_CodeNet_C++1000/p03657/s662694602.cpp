#include <bits/stdc++.h>
using namespace std;
#define int long long
int findLowerBound(
    vector<pair<int, int>> &arr,
    pair<int, int> &p)
{

    auto low = lower_bound(arr.begin(),
                           arr.end(), p);

    return low - arr.begin();
}
int findUpperBound(
    vector<pair<int, int>> &arr,
    pair<int, int> &p)
{
    auto up = upper_bound(arr.begin(),
                          arr.end(), p);

    return up - arr.begin();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    int n, m;
    cin >> n >> m;
    if ((n + m) % 3 == 0 || n % 3 == 0 || m % 3 == 0)
    {
        cout << "Possible"
             << "\n";
    }
    else
    {
        /* code */
        cout << "Impossible"
             << "\n";
    }

    cin >> str;

    return 0;
}

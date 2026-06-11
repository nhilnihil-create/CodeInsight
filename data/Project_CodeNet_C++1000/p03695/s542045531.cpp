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
    int r, g, b;
    cin >> r;
    int arr[r];
    int a[10] = {0};
    int max1 = 0, min1 = 10001;
    for (int i = 0; i < r; i++)
    {
        cin >> arr[i];
        if (arr[i] < 400)
        {
            a[0]++;
        }
        if (arr[i] > 399 && arr[i] < 800)
        {
            a[1]++;
        }
        if (arr[i] > 799 && arr[i] < 1200)
        {
            a[2]++;
        }
        if (arr[i] > 1199 && arr[i] < 1600)
        {
            a[3]++;
        }
        if (arr[i] > 1599 && arr[i] < 2000)
        {
            a[4]++;
        }
        if (arr[i] > 1999 && arr[i] < 2400)
        {
            a[5]++;
        }
        if (arr[i] > 2399 && arr[i] < 2800)
        {
            a[6]++;
        }
        if (arr[i] > 2799 && arr[i] < 3200)
        {
            a[7]++;
        }
        if (arr[i] > 3199)
        {
            a[8]++;
        }
    }
    int count = 0;

    for (int i = 0; i < 8; i++)
    {
        if (a[i] != 0)
            count++;
    }
    if (count)
        cout << count << " ";
    else
    {
        if (a[8] == 0)
            cout << 0 << "\n";
        else
        {

            cout << 1 << " ";
        }
    }

    cout << count + a[8] << " ";

    return 0;
}

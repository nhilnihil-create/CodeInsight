#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 5;

int n, a[N];
bool b[N];
bool check(int x)
{
    for(int i = 1; i < 2 * n; i++)
        b[i] = (a[i] >= x);

    if(b[n] == b[n - 1] || b[n] == b[n + 1])
        return b[n];

    int first_right = n + 1;
    while(first_right < 2 * n && b[first_right] != b[first_right - 1])
        first_right++;

    int first_left = n - 1;
    while(first_left && b[first_left] != b[first_left + 1])
        first_left--;

    if(first_left == 0)
        return b[first_right - 1];
    if(first_right == 2 * n)
        return b[first_left + 1];

    return (first_left > 2 * n - first_right) ? b[first_left] : b[first_right];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i < 2 * n; i++)
        cin >> a[i];

    int low = 1, high = N - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(check(mid))
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << low - 1 << endl;

    return 0;
}

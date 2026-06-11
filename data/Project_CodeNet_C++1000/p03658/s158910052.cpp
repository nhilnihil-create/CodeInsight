#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> l(n);

    rep(i, n)
    {
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    int sum = 0;
    for (int i = n - 1; i >= n - k; i--)
    {
        sum += l[i];
    }
    cout << sum << endl;
    return 0;
}

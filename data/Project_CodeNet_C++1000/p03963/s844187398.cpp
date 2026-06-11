#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    int n, k;
    int ans = 1;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            ans *= k;
        }
        else
        {
            ans *= k - 1;
        }
    }
    cout << ans << endl;
}
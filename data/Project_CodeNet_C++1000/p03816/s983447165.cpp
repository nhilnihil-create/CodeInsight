#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> checked(100005);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (checked[a] > 0)
        {
            ans++;
        }
        checked[a]++;
    }
    cout << n - ans - ans % 2 << endl;
    return 0;
}
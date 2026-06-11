#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[250];
int main()
{
	IOS;
    int n;
    cin>>n;
    for (int i = 1; i <= 2*n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 2 * n + 1);
    int ans = 0;
    for (int i = 1; i <= 2 * n; i += 2)
    {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}

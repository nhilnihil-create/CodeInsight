#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
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
const int maxn = 1e5 + 10;
int a[maxn];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (i + 1 > a[i + 1])
        {
            int j = 0;
            for (; a[i + j + 1] == i; j++)
                ;
            if ((a[i] - i) % 2 == 1 || j % 2 == 1)
                cout << "First"<<endl;
            else
                cout << "Second"<<endl;
            break;
        }
    }
    return 0;
}
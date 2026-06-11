#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    map<int, int> dic;
    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < 8; k++)
        {
            if (a[i] >= 400 * k && a[i] < 400 * (k + 1))
            {
                ++dic[k];
            }
        }
        if (a[i] >= 3200) ++num;
    }
    int minval = dic.size() > 0 ? dic.size() : 1;
    int maxval = dic.size() + num;
    printf("%d %d\n", minval, maxval);
    return 0;
}

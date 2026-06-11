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
        if (a[i] >= 1 && a[i] < 400)
        {
            ++dic[0];
        }
        else if (a[i] >= 400 && a[i] < 800)
        {
            ++dic[1];
        }
                else if (a[i] >= 800 && a[i] < 1200)
        {
            ++dic[2];
        }
        else if (a[i] >= 1200 && a[i] < 1600)
        {
            ++dic[3];
        }
        else if (a[i] >= 1600 && a[i] < 2000)
        {
            ++dic[4];
        }
        else if (a[i] >= 2000 && a[i] < 2400)
        {
            ++dic[5];
        }
        else if (a[i] >= 2400 && a[i] < 2800)
        {
            ++dic[6];
        }
        else if (a[i] >= 2800 && a[i] < 3200)
        {
            ++dic[7];
        }
        else
        {
            ++num;
        }
    }
    int minval = dic.size() > 0 ? dic.size() : 1;
    int maxval = dic.size() + num;
    printf("%d %d\n", minval, maxval);
    return 0;
}


/*
   О НЕТ! ОНИ ДОГОНЯЮТ!!!
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
*/

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> a(m);
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i] % 2;
    }
    for (int i = 0; i < m; i++)
    {
        if (a[i] % 2)
        {
            if (a[0] % 2 == 0)
            {
                swap(a[0], a[i]);
            }
            else
            {
                swap(a[i], a[m - 1]);
            }
        }
    }
    if (sum > 2)
    {
        puts("Impossible");
        return 0;
    }
    if (m == 1)
    {
        if (a[0] == 1)
        {
            cout << a[0] << '\n';
            cout << 1 << '\n';
            cout << a[0] << '\n';
        }
        else
        {
            cout << a[0] << '\n';
            cout << 2 << '\n';
            cout << a[0] - 1 << ' ' << 1 << '\n';
        }
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
    if (a[0] == 1)
    {
        cout << m - 1 << '\n'; 
        for (int i = 1; i < m - 1; i++)
        {
            cout << a[i] << ' ';
        }
    }
    else
    {
        a[0]--;
        cout << m << '\n';
        for (int i = 0; i < m - 1; i++)
        {
            cout << a[i] << ' ';
        }
    }
    a[m - 1]++;
    cout << a[m - 1];
    cout << '\n';
}

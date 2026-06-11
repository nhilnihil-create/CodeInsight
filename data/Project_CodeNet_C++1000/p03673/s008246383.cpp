#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int n;
    cin >> n;

    deque<int> b;
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (i % 2 != 0)
        {
            b.push_back(a);
        }
        else
        {
            b.push_front(a);
        }
    }

    if (n % 2 != 0)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            printf("%d", b[i]);
            if (i != 0)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d", b[i]);
            if (i != n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
    }

    return (0);
}
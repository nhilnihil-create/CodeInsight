#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;


int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    if (x == 1 || x == 2 * n - 1)
        puts("No");
    else
    {
        puts("Yes");
        vector<int>A(2 * n, -1);

        A[n - 2] = x - 1;
        A[n - 1] = x;
        A[n] = x + 1;
        int now = 1;

        for (int i = 0; i < 2 * n - 1; i++)
        {
            if (A[i] == -1)
            {
                while (abs(now - x) <= 1)
                    now++;
                A[i] = now++;
            }
        }
        
        for (int i = 0; i < 2 * n - 1; i++)
            printf("%d\n", A[i]);
    }
}

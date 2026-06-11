#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fl first
#define fr second
using namespace std;
  
typedef long long LL;
typedef pair<int, int> pii;
const int N = 20000 + 5;

int n, a[N], b[N], p[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++)
    {
        a[i] = 30000 * i;
        b[i] = 30000 * (n - i + 1);
    }
    for (int i = 1; i <= n; i++) a[p[i]] -= n - i + 1;
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
    return 0;
}

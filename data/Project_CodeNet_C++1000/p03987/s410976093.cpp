#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n;
int a[500000];
int pos[500000];
long long ans;
int L[500000];
int R[500000];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pos[a[i]] = i;
    for (int i = 1; i <= n; i++) L[i] = i - 1;
    for (int i = 1; i <= n; i++) R[i] = i + 1;
    for (int i = n; i >= 1; i--)
    {
        long long LL = L[pos[i]], RR = R[pos[i]];
        ans += (pos[i] - LL) * (RR - pos[i]) * i;
        L[RR] = LL;
        R[LL] = RR;
    }
    cout << ans;
}

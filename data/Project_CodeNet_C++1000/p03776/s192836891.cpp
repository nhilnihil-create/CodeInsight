#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b;
long long v[50];
long long cnk[51][51];

int main()
{
    for (int i = 0; i <= 50; i++) cnk[i][0] = 1, cnk[i][i] = 1;
    for (int i = 1; i <= 50; i++) for (int j = 1; j < i; j++) cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v, v + n);
    reverse(v, v + n);
    if (a > b)
    {
        cout << 0 << "\n" << 0 << "\n";
        return 0;
    }
    long long summ = 0;
    for (int i = 0; i < a; i++) summ += v[i];
    printf("%.15f\n", (double)summ / a);
    long long ans = 0;
    int kek = 0, lol = 0;
    for (int j = 0; j < n; j++) if (v[j] == v[a - 1]) kek++, lol += (j <= a - 1);
    if (v[0] == v[a - 1])
    {
        for (int i = a; i <= b && i <= kek; i++) ans += cnk[kek][i];
        printf("%lld", ans);
        return 0;
    }
    printf("%lld", cnk[kek][lol]);
}

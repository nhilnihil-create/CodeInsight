#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> num(1e5 + 1, 0);
    int a;
    rep(i, n)
    {
        cin >> a;
        num[a]++;
        num[a + 1]++;
        if (a != 0)
        {
            num[a - 1]++;
        }
    }
    int res;
    int cnt = 0;
    rep(i, 1e5 + 1)
    {
        if (num[i] > cnt)
        {
            cnt = num[i];
        }
    }
    cout << cnt << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    map<int, int> A;
    int cnt = 0;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (A[a] == 1)
            cnt++;
        else
            A[a]++;
    }
    cout << n - 2 * ((cnt + 1) / 2) << endl;
}
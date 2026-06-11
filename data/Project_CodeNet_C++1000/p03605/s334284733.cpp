#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    int n;
    cin >> n;
    if ((n / 10) == 9 || n - (int)(n / 10) * 10==9)
    {
        cout << "Yes" << "\n";
    }else{
        cout << "No" << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    int ans;

    cin >> N;

    if (N == 1) {
        ans = 1;
    } else {
        ans = N * (N+1) / 2;
    }

    cout << ans << endl;

    return 0;
}
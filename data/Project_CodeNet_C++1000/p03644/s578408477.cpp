#include<bits/stdc++.h>
#include <vector>
#define endl '\n';
using namespace std;

int main()
{
    int n; cin >> n;
    int ans = 1;
    while (ans * 2 <= n)
        ans *= 2;
    cout << ans;
    return 0;
}
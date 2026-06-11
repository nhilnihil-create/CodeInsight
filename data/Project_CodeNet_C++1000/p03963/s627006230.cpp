#include <iostream>
using namespace std;

void solve()
{
    int n, k; cin >> n >> k;
    long long ans = k;
    n--;
    int mul = k-1;

    while(n--){
        ans *= mul;
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
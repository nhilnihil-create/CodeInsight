#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    ll a = 1000000000+7;
    int N;
    ll ans = 1;
    cin >> N;

    for(int i = 1;i <= N;i++){
        ans = ans*i%a;
    }

    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const int MOD = 1000000007;
const ll INF = 1LL << 60;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int w, a, b;
    cin >> w >> a >> b;
    int ans = abs(a-b)-w;
    if(ans<=0) {
        ans = 0;
    }
    cout << ans << endl;
}
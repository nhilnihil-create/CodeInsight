#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
ll a[maxn];
int aim, ans = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for(int i = 1; i < maxn; i++) a[i] = a[i-1] + i;
    cin>>aim;
    while(a[ans] < aim) ans++;
    cout<<ans<<endl;
    return 0;
}

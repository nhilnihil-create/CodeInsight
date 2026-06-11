#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int n,a[200001];
int ans=1;
int main()
{
	int ans=1;
    cin >> n;
    for (int i=1;i<=n;i++)cin >> a[i];
    for (int i=1,d=0;i<=n;i++)
    {
        d=max(d,i-1-(a[i-1]+1)/2);
        ans=1ll*ans*(i-d)%MOD;
    }
    cout << ans;
}
#include<bits/stdc++.h>
#define int long long
const int N=100010;
using namespace std;

int n,a[N],ans;
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        if(a[i]==a[i-1])
			ans++;
    if(ans%2==1)ans++;
    cout<<n-ans<<"\n";
	return 0;
}
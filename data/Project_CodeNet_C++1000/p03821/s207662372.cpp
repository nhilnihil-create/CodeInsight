#include<bits/stdc++.h>
using namespace std;
long long a[100009],b[100009];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long  n,i,j;
    cin >> n;
    for(i=0;i<n;i++)
        cin >> a[i] >> b[i];
    long long ans = 0LL;

    for(i=n-1;i>=0;i--)
    {
        a[i]+=ans;
        if(a[i]%b[i])
        {
            ans+=(b[i]-a[i]%b[i]);
        }
    }
    cout << ans << endl;

}

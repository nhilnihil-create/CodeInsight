#include<bits/stdc++.h>
using namespace std;
long long a[300009];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long  n,i,j,ans=0LL;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i-1] && a[i])
        {
            ans++;
            a[i]--;
        }
        ans+=(a[i]/2);
        a[i]%=2;
    }
    cout << ans << endl;
}

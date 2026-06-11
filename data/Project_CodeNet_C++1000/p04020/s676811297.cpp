#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,bns=0,m;
    long long ans=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> m;
        if(m)
        {
            m+=bns;
        }
        else
        {
            bns=0;
        }
        ans+=m/2;
        bns=m%2;
    }
    cout << ans << endl;
    return 0;
}

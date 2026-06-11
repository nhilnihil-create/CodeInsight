#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<int>())
using namespace std;
int main()
{
    speed_up;
    map<ll,ll>m;
    ll i, ans = 1, a, flag = 0, n;
    cin>>n;
    a = n;
    while(a--)
    {
        ll j;
        cin>>j;
        m[j]++;
        if(m[j]>2) flag++;
    }
    if(flag != 0)
    {
       cout<<0<<endl;
       return 0;
    }
    if(n%2 != 0 && m[0] != 1)
    {
        cout<<0<<endl;
        return 0;
    }
        for(i = 1; i<=n; i+=2)
        {
            if(m[i]!=2 && n%2 == 0)
            {
                cout<<0<<endl;
                return 0;
            }

        }
       for(i = 1; i<=n/2; i++)
       {
           ans*=2;
           ans%= (ll) 1e9 + 7;
       }
       cout<<ans<<endl;


       return 0;


}

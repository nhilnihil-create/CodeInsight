#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define sq(x)           ((x)*(x))
#define pi              acos(-1.0)
#define NUM             1000005

typedef long long ll;


int main()
{
    FastRead

    ll n,cnt=0,ans=0;

    cin>>n;

    vector<ll>v(3*n);

    for(auto &it:v)
        cin>>it;

    sort(v.begin(),v.end(),greater<ll>());

    for(ll i = 0; i < 3*n; i++)
    {
        if (cnt == n)
            break;
        if (i%2 != 0)
        {
            cnt++;
            ans += v[i];
        }
    }

    cout<<ans<<endl;
}

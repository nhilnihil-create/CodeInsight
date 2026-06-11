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

    ll n, k,mx = -1, gcd;

    cin >> n >> k;

    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin >> temp;

        if(i==0)
            gcd = temp;
        else
            gcd = __gcd(gcd, temp);

        mx = max(mx, temp);
    }

    if(k > mx || k % gcd)
        cout<<"IMPOSSIBLE"<<endl;
    else
        cout<<"POSSIBLE"<<endl;
}

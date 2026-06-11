#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,a,b,h[100005];

bool prov(long long t)
{
    ll ost=0;
    for(ll i=0;i<n;i++)
    {
        ll tr=h[i]-b*t;
        if(tr>0)
        {
            ll y=tr/(a-b)+((tr%(a-b))!=0);
            ost+=y;
        }
    }
    return ost<=t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>a>>b;
    for(ll i=0;i<n;i++)
        cin>>h[i];
    sort(h,h+n);

    ll levo=1,desno=1e10;
    while(levo<=desno)
    {
        ll tren=(levo+desno)/2;
        if(prov(tren))
            desno=tren-1;
        else
            levo=tren+1;
        //cout<<ind<<endl;
    }

    cout<<levo<<endl;

    return 0;
}

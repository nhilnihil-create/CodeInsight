#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ll w,h,n;
cin >> w >> h >> n;
ll mnx = 0 , mny = 0 , mxx = w ,mxy = h;


for(int i=0; i<n; i++)
{
    ll x,y,a;
    cin >> x >> y >> a;
    if(a==1)
    {
     mnx = max(x,mnx) ;

    }
    else if(a==2)
    {
     mxx = min(x,mxx);
    }
    else if(a==3)
    {
        mny = max(y,mny);
    }
    else if(a==4)
    {
        mxy = min(y,mxy);
    }

}

ll hi = mxx - mnx , wi = mxy - mny;

if(mxx<mnx || mxy<mny)
cout << 0 << endl;
else
    cout << hi*wi << endl;

  }

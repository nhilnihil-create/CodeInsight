#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int n,i;
    cin>>n;
    ll a[n];
    for (i=0;i<n;i++)
        cin>>a[i];
    ll tans1=0,tans2=0,tp1=0,tp2=0;
    for (i=0;i<n;i++)
    {
        tp1+=a[i];
        tp2+=a[i];
        if (i&1)
        {
            if (tp1>=0)
            {
                tans1+=(tp1+1);
                tp1=-1;
            }
            if (tp2<=0)
            {
                tans2+=(1-tp2);
                tp2=1;
            }
        }
        else
        {
            if (tp1<=0)
            {
                tans1+=(1-tp1);
                tp1=1;
            }
            if (tp2>=0)
            {
                tans2+=(tp2+1);
                tp2=-1;
            }
        }
    }
    cout<<min(tans1,tans2)<<endl;
}
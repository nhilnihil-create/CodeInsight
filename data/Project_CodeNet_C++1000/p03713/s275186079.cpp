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
    ll h,w,i;
    cin>>h>>w;
    ll ans=INT_MAX,p;
    for (i=1;i<h;i++)
    {
        vector<ll> s;
        s.pb(i*w);
        p=h-i;
        if (p%2==0)
        {
            if (p/2!=0)
            {
                s.pb(w*(p/2));
                s.pb(w*(p/2));
                ans=min(ans,*max_element(s.begin(),s.end())-*min_element(s.begin(),s.end()));
            }
        }
        else
        {
            if (p/2!=0 && p/2+1!=0)
            {
                s.pb(w*(p/2));
                s.pb(w*(p/2+1));
                ans=min(ans,*max_element(s.begin(),s.end())-*min_element(s.begin(),s.end()));
            }
        }
        s.clear();
        s.pb(i*w);
        if (w%2==0)
        {
            if (w/2!=0)
            {
                s.pb((w/2)*p);
                s.pb((w/2)*p);
                ans=min(ans,*max_element(s.begin(),s.end())-*min_element(s.begin(),s.end()));
            }
        }
        else
        {
            if (w/2!=0 && w/2+1!=0)
            {
                s.pb((w/2)*p);
                s.pb((w/2+1)*p);
                ans=min(ans,*max_element(s.begin(),s.end())-*min_element(s.begin(),s.end()));
            }
        }
    }
    for (i=1;i<w;i++)
    {
        vector<ll> s;
        s.pb(i*h);
        p=w-i;
        if (p%2==0)
        {
            if (p/2!=0)
            {
                s.pb(h*(p/2));
                s.pb(h*(p/2));
                ans=min(ans,*max_element(s.begin(),s.end())-*min_element(s.begin(),s.end()));
            }
        }
        else
        {
            if (p/2!=0 && p/2+1!=0)
            {
                s.pb(h*(p/2));
                s.pb(h*(p/2+1));
                ans=min(ans,*max_element(s.begin(),s.end())-*min_element(s.begin(),s.end()));
            }
        }
        s.clear();
        s.pb(i*h);
        if (h%2==0)
        {
            if (h/2!=0)
            {
                s.pb(h/2*p);
                s.pb(h/2*p);
                ans=min(ans,*max_element(s.begin(),s.end())-*min_element(s.begin(),s.end()));
            }
        }
        else
        {
            if (h/2!=0 && h/2+1!=0)
            {
                s.pb((h/2)*p);
                s.pb((h/2+1)*p);
                ans=min(ans,*max_element(s.begin(),s.end())-*min_element(s.begin(),s.end()));
            }
        }
    }
    cout<<ans<<endl;
}
#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long
using namespace std;

ll solve(ll h, ll w)
{
    ll res = h*w;
    ll t_area = h*w;
    for(ll i=1; i<w; i++)
    {
        ll a = i*h;
        ll b = (w-i)*(h/2);
        ll c = t_area - a - b;
        ll tmp = max({a,b,c}) - min({a,b,c});
        res = min(res, tmp);
//        cout<<a<<" "<<b<<" "<<c<<" "<<tmp<<"\n";
    }
//    cout<<"------\n";
    for(ll i=1; i<h; i++)
    {
        ll a = i*w;
        ll b = (h-i)*(w/2);
        ll c = t_area - a - b;
        ll tmp = max({a,b,c}) - min({a,b,c});
        res = min(res, tmp);
//        cout<<a<<" "<<b<<" "<<c<<" "<<tmp<<"\n";
    }
    res = min({res, w, h});
    return res;
}

int main() {
    
    ll h, w;
    cin >> h >> w;
    if(h % 3 == 0 || w % 3 == 0) cout << 0 << endl;
    else
        cout << solve(h, w);
    
    return 0;
}
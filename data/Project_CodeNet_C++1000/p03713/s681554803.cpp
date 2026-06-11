#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50

int main()
{
    ll h, w;
    cin >> h >> w;
    ll diff = infll;
    for(ll a = 1; a <= h-1; a++)
    {
        if(a < h-1)
        {
        ll recta = a*w;
        ll rectb = ((h-a)/2)*w;
        ll rectc = h*w - recta - rectb;
        diff = min(diff, max(recta, max(rectb, rectc)) - min(recta, min(rectb, rectc)));

        rectb = (h-a)*(w/2);
        rectc = h*w - recta - rectb;
        diff = min(diff, max(recta, max(rectb, rectc)) - min(recta, min(rectb, rectc)));
        }
        else
        {
            ll recta = a*w;
            ll rectb = (h-a)*(w/2);
            ll rectc = h*w - recta - rectb;
            diff = min(diff, max(recta, max(rectb, rectc)) - min(recta, min(rectb, rectc)));
        }
    }

    for(ll a = 1; a <= w-1; a++)
    {
        if(a < w - 1)
        {
        ll recta = a*h;
        ll rectb = ((w-a)/2)*h;
        ll rectc = h*w - recta - rectb;
        diff = min(diff, max(recta, max(rectb, rectc)) - min(recta, min(rectb, rectc)));

        rectb = (w-a)*(h/2);
        rectc = h*w - recta - rectb;
        diff = min(diff, max(recta, max(rectb, rectc)) - min(recta, min(rectb, rectc)));
        }
        else
        {
            ll recta = a*h;
            ll rectb = (w-a)*(h/2);
            ll rectc = h*w - recta - rectb;
            diff = min(diff, max(recta, max(rectb, rectc)) - min(recta, min(rectb, rectc)));
        }
    }

    cout << diff << endl;
}

 #include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define pi pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 300004
#define INF 1e9+7

using namespace std;

ll n;
string stn;

string tostr(ll x)
{
    string res="";
    string tmp = "0";

    while(x)
    {
        tmp[0] = x%10;
        x/=10;
        res+=x;
    }

    return res;
}

ll query(ll x)
{
    cout << "? " << x << "\n";
    cout.flush();

    char c='N';
    cin >> c;

    return (c=='Y');
}

ll EX(ll v,ll e)
{
    ll p = 1;

    rep(i,0,e)
        p*=v;
        return p;
}

int main()
{
    ios_base::sync_with_stdio(false);

    if(query(1000000000000))
    {
        ll low = 1;
        ll high = 11;
        ll digits = 12;

        while(low <= high)
        {
            ll mid = (low+high)/2;

            bool q = query(EX(10,mid)-1);

            if(q)
            {
                high=mid-1;
                digits=min(digits,mid);
            }
            else
            {
                low=mid+1;
            }
        }

        cout << "! "<<EX(10,digits-1) << "\n";
        cout.flush();
        return 0;
    }

    ll low = 1;
    ll high = 9;
    ll digits = 1;

    while(low <= high)
    {
        ll mid = (low+high)/2;

        bool q = query(EX(10,mid));

        if(q)
        {
            low = mid+1;
            digits = max(digits,mid+1);
        }
        else
        {
            high=mid-1;
        }
    }

    ll answer = 0;

    rep(i,0,digits-1)
    {
        low = 0;
        high = 9;
        ll d = 0;

        while(low <= high)
        {
            ll mid = (low+high)/2;

            bool q = query(answer*10+mid);

            if(q)
            {
                low=mid+1;
                d=max(d,mid);
            }
            else
            {
                high=mid-1;
            }
        }

        answer = answer*10+d;
    }

    low = 0;
    high = 9;
    ll d = 9;

    while(low <= high)
    {
        ll mid = (low+high)/2;

        bool q = query(answer*100+10*mid+0);

        if(q)
        {
            high=mid-1;
            d=min(d,mid);
        }
        else
        {
            low=mid+1;
        }
    }

    answer = answer*10+d;

    cout << "! " <<answer << "\n";
    cout.flush();

    return 0;
}


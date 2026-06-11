
///HELLO THERE~!
///CREATED BY MD SADMAN MEHEDI SIVAN(IUT CSE[SWE'19])

#include<bits/stdc++.h>
using namespace std;

#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define READ            freopen("input.txt","r",stdin);
#define WRITE           freopen("red.txt","w",stdout);

using ll=long long;
using ull=unsigned long long;
const double pi = 2*acos(0.0);
const long long MX = 2e5+7;

int main()
{
    long long n;
    ll k;
    cin >> n >> k;

    ll a[n];

    long long flag = 0;


    ll max = 0;


    for(long long i = 0; i < n; i++)
    {
        cin >> a[i];
        if(max < a[i])
        {
            max = a[i];
        }
        if(a[i] == k)
        {
            flag = 1;
        }
    }

    if(flag==1)
    {

        cout << "POSSIBLE" << endl;
        return 0;

    }



    if(flag == 0)
    {
        ll b = a[0];
        for(ll i = 1; i < n; i++)
        {
            b = __gcd(b, a[i]);

            if(b == 1)
            {
                break;
            }
        }

        if(k % b == 0 && k <= max)
        {
            flag = 1;
        }
    }

    if(flag == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << "POSSIBLE" << endl;
    }
}

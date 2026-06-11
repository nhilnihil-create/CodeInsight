#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vp vector<pair<int, int>>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50

ll gcd(ll a, ll b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return a/g * b; //prevent overflow
}

/////////////////////////  END OF TEMPLATE ////////////////////////////////////////


int main()
{
    string s;
    cin >> s;
    set<char> v;
    for(int i = 0 ; s[i]; ++i)
    {
        v.insert(s[i]);
    }

    if(v.size() == 26)
    {
        cout << "None" << endl;
    }
    else
    {
        char ans = 'a';
        for(int i = 0; i < 26; ++i)
        {
            if(!v.count(ans+i))
            {
                ans += i;
                break;
            }

        }
        cout << ans << endl;
    }
}
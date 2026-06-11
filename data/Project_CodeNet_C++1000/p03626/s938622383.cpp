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
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    int statec;
    int statep = (s1[0] == s2[0]) ? 0 : 1;
    ll ans = (statep) ? 6 : 3;
    int i = (statep) ? 2 : 1;
    while(i < n)
    {
        statec = (s1[i] == s2[i]) ? 0 : 1;

        if(statec == 0 && statep == 0)
        {
            ans = (ans*2)%1000000007;
        }
        else if (statec == 1 && statep == 0)
        {
            ans = (ans*2)%1000000007;
        }
        else if (statec == 1 && statep == 1)
        {
            ans = (ans*3)%1000000007;
        }
        statep = statec;
        if(statec == 0)
        {
            i++;
        }
        else
        {
            i += 2;
        }
    }

    cout << ans << endl;


}

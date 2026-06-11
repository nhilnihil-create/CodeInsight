/*
    Author: Aryan Yadav
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define f(i, a, b) for (long long i = a; i < b; i++)
#define rep(i, a, b) for (long long i = a; i <= b; i++)
#define fm(i, a, b) for (long long i = a; i > b; i--)
#define repm(i, a, b) for (long long i = a; i >= b; i--)
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
#define pqmaxi priority_queue<int>
#define pqmaxl priority_queue<ll>
#define pqmini priority_queue<int, vi, greater<int>>
#define pqminl priority_queue<ll, vl, greater<ll>>
#define all(x) x.begin(), x.end()
#define test     \
    ll test;     \
    cin >> test; \
    while (test--)
#define pb(i) push_back(i)
#define mp(i, j) make_pair(i, j)
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

int main()
{
    fast;
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    ll s1 = a + b;
    ll yc = 0;
    ll ycb = 0;
    ll len = s.length();
    f(i, 0, len)
    {
        if (s[i] == 'a')
        {
            if (yc < s1)
            {
                cout << "Yes\n";
                yc++;
            }
            else
            {
                cout << "No\n";
            }
        }
        else if (s[i] == 'b')
        {
            ycb++;
            if (yc < s1)
            {
                if (ycb <= b)
                {
                    cout << "Yes\n";
                    yc++;
                }
                else
                {
                    cout << "No\n";
                }
            }
            else
            {
                cout << "No\n";
            }
        }
        else
        {
            cout << "No\n";
        }
    }
}
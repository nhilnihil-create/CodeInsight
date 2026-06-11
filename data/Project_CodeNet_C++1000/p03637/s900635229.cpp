#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vp vector<pair<int, int>>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    while(n--)
    {
        int a;
        cin >> a;
        mp[a%4]++;
    }
    if(mp[2] % 2 == 0)
    {
        if(mp[1] + mp[3] - mp[0] <= 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        if(mp[1] + mp[3] + 1 - mp[0] <= 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

}
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
    string s;
    cin >> s;
    bool rp = 0;
    map<int, int> mp;
    for(int i = 0; s[i]; i++)
    {
        if((++mp[s[i]-'a']) > 1)
        {
            rp = 1;
        }
    }
    if(rp)
    {
        cout << "no" << endl;
    }
    else
    {
        cout << "yes" << endl;
    }
}

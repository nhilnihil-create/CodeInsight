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
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 1; i < s.size()/2; ++i)
    {
        if(s.substr(0, i) == s.substr(i, i))
        {
            ans = i;
        }
    }
    cout << 2*ans << endl;
}

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
    int n, m;
    cin >> n >> m;
    set<int> s1;
    vi v;
    bool solve = 0;
    for(int i = 0 ; i<m; ++i)
    {
        int a, b;
        cin >> a >> b;
        if(a == 1)
        {
            s1.insert(b);
        }
        if(b == n)
        {
            v.pb(a);
        }

    }

    for(int i = 0; i < v.size(); ++i)
    {
        if(s1.count(v[i]))
        {
            solve = 1;
            break;
        }
    }

    if(solve)
    {
        cout << "POSSIBLE" << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
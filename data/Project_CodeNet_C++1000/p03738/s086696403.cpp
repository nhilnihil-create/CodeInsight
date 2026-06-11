#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define mset(arr, val) memset((arr), (val), sizeof(arr))
#define For(i, init, n) for (int64_t (i) = (init); (i) < (n); (i)++)
#define ___ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

// const double PI = acos(-1.0), E = exp(1.0), EPS = 1e-9;
const int MOD = (int)1e9 + 7, N = (int)1e5;

int main()
{   
#ifdef MY_PREPROCESSOR
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ___
    
    string n, m;
    cin >> n >> m;
    if (n.length() > m.length())
    {
        cout<< "GREATER";
    }
    else if (n.length() < m.length())
    {
        cout<< "LESS";
    }
    else
    {
        if (n.compare(m) > 0)
            cout<< "GREATER";
        else if (n.compare(m) < 0)
            cout<< "LESS";
        else
            cout<< "EQUAL";
    }
    
    return 0;
}
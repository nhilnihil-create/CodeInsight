#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

const string possible = "POSSIBLE";
const string impossible = "IMPOSSIBLE";
int n, k, a[101010];

int main()
{
    cin >> n >> k;
    int m = 0;
    rep(i, n)
    {
        cin >> a[i];
        if(a[i] == k)
        {
            cout << possible << endl;
            return 0;
        }
        m = max(m, a[i]);
    }
    if(k >= m)
    {
        cout << impossible << endl;
        return 0;
    }
    
    int g = a[n - 1];
    rep(i, n - 1)
    {
        g = __gcd(g, a[i]);
    }
    
    if(k % g != 0)
    {
        cout << impossible << endl;
    }
    else
    {
        cout << possible << endl;
    }
    
    

    return 0;
}
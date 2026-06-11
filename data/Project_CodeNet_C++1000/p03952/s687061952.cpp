#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int INF = 1e9+10;
int main()
{
    int n, x;
    cin >> n >> x;
    n = 2 * n - 1;
    if(x == 1 || x == n)
    {
        cout << "No" << endl;
        return 0;
    }
    else cout << "Yes" << endl;
    if(n == 3)
    {
        cout << 1 << endl;
        cout << 2 << endl;
        cout << 3 << endl;
        return 0;
    }
    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(i);
    if(x == n-1)
    {
        s.erase(x);
        s.erase(x+1);
        s.erase(x-1);
        s.erase(x-2);
        for(int i = 0; i < n/2-2; i++)
        {
            cout << *s.begin() << endl;
            s.erase(s.begin());
        }
        cout << x-2 << endl;
        cout << x+1 << endl;
        cout << x << endl;
        cout << x-1 << endl;
        while(!s.empty())
        {
            cout << *s.begin() << endl;
            s.erase(s.begin());
        }
    }
    else
    {
        s.erase(x);
        s.erase(x-1);
        s.erase(x+1);
        s.erase(x+2);
        for(int i = 0; i < n/2-2; i++)
        {
            cout << *s.begin() << endl;
            s.erase(s.begin());
        }
        cout << x+2 << endl;
        cout << x-1 << endl;
        cout << x << endl;
        cout << x+1 << endl;
        while(!s.empty())
        {
            cout << *s.begin() << endl;
            s.erase(s.begin());
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    if(x == 1 || x == 2*n-1)
    {
        cout << "No" << endl;
        return 0;
    }
    if(n == 2)
    {
        cout << "Yes" << endl;
        cout << 1 << endl << 2 << endl << 3 << endl;
        return 0;
    }
    set<int> s;
    for(int i = 1; i <= 2*n-1; i++)
    {
        s.insert(i);
    }
    s.erase(x);
    s.erase(x-1);
    s.erase(x+1);
    if(x != 2*n-2)
    {
        s.erase(x+2);
    }
    else
    {
        s.erase(x-2);
    }
    cout << "Yes" << endl;
    auto itr = s.begin();
    for(int i = 1; i <= n-2; i++)
    {
        cout << *itr << endl;
        itr++;
    }
    if(x != 2*n-2)
    {
        cout << x+2 << endl;
        cout << x << endl;
        cout << x-1 << endl;
        cout << x+1 << endl;
    }
    else
    {
        cout << x-1 << endl;
        cout << x << endl;
        cout << x+1 << endl;
        cout << x-2 << endl;
    }
    while(itr != s.end())
    {
        cout << *itr << endl;
        itr++;
    }
}

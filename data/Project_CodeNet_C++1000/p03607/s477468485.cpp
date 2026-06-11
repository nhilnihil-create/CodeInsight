#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    set<int> s;
    cin >> n;
    while(n--)
    {
        cin >> m;

        set<int>::iterator it=s.find(m);
        if(it==s.end()) s.insert(m);
        else s.erase(it);
    }

    cout << s.size();

    return 0;
}
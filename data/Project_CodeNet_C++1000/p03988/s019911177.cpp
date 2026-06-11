#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n;
    cin >> n;
    multiset<int> ms;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ms.insert(a);
    }
    int h = *ms.rbegin();
    if(h % 2 == 0)
    {
        if(ms.count(h/2) != 1)
        {
            cout << "Impossible" << endl;
            return 0;
        }
        ms.erase(h/2);
        for(int i = h/2 + 1; i <= h; i++)
        {
            if(ms.count(i) < 2)
            {
                cout << "Impossible" << endl;
                return 0;
            }
            ms.erase(i);
        }
        if(ms.empty()) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }
    else
    {
        if(ms.count(h/2+1) != 2)
        {
            cout << "Impossible" << endl;
            return 0;
        }
        ms.erase(h/2+1);
        for(int i = h/2 + 2; i <= h; i++)
        {
            if(ms.count(i) < 2)
            {
                cout << "Impossible" << endl;
                return 0;
            }
            ms.erase(i);
        }
        if(ms.empty()) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }
}



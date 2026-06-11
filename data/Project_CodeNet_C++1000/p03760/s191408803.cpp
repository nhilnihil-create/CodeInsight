#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string o,e;
    cin >> o;
    cin >> e;

    for (int i = 0; i < e.length(); i++)
    {
        cout << o.at(i);
        cout << e.at(i);
    }
    if(o.length()-e.length()==1) cout << o.at(o.length()-1);
    cout << endl;
    return 0;
}
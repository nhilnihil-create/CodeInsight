#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int main()
{
    string o, e;
    cin >> o >> e;
    for(int i = 0 ; i < min(o.size(), e.size()); i++)
    {
        cout << o[i];
        cout << e[i];
    }

    if(o.size() > e.size())
    {
        cout << o[o.size()-1] << endl;
    }
    else if (o.size() < e.size())
    {
        cout << e[e.size()-1] << endl;
    }
    else
    {
        cout << endl;
    }
}

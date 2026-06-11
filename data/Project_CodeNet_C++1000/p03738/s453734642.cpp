#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);

    string a, b;

    cin >> a >> b;

    if(a.size() > b.size())
    {
        cout << "GREATER\n";
        return 0;
    }
    else if(a.size() < b.size())
    {
        cout << "LESS\n";
        return 0;
    }
    else if(a == b)
    {
        cout << "EQUAL\n";
        return 0;
    }

    int i;
    for(i = 0; i < a.size(); i++)
        if(a[i] != b[i])
            break;

    if(a[i] > b[i])
        cout << "GREATER\n";
    else
        cout << "LESS\n";

    return 0;

}

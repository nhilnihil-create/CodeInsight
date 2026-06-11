#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    int c5 = 0, c7 = 0;

    if(a == 5)
    {
        c5++;
    }
    else if(a == 7)
    {
        c7++;
    }

    if(b == 5)
    {
        c5++;
    }
    else if(b == 7)
    {
        c7++;
    }

    if(c == 5)
    {
        c5++;
    }
    else if(c == 7)
    {
        c7++;
    }

    if(c5 == 2 && c7 == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int jdg(int x)
{
    int g = 2;
    vector<int> ary = {4, 6, 9, 12};
    if (x == 2)
    {
        g = 0;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (ary.at(i) == x)
            {
                g = 1;
                break;
            }
        }
    }
    return g;
}

int main()
{
    int a, b;
    cin >> a >> b;
    if (jdg(a) == jdg(b))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
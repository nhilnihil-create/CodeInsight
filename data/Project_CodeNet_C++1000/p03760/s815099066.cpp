#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    string o, e, ans;
    cin >> o >> e;
    int length = o.size() + e.size();
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            ans += o.at(i / 2);
        }
        else
        {
            ans += e.at(i / 2);
        }
    }
    cout << ans << endl;

    return 0;
}
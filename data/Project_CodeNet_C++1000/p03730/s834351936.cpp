#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    int aa, a, b, c, i = 0, m;
    vector<int> box(110); //1<=A<=100より、余りは99通り
    cin >> aa >> b >> c;

    while (true)
    {
        i++;
        a = aa * i;
        m = a % b;
        if (m == c)
        {
            cout << "YES" << endl;
            return 0;
        }
        if (count(box.begin(), box.end(), m))
        {
            cout << "NO" << endl;
            return 0;
        }
        box.push_back(m);
    }
    return 0;
}
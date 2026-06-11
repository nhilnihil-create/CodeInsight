#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int odd = 0;

    for (int i : a)
    {
        cin >> i;
        if (i % 2 != 0)
            odd++;
    }

    if (odd % 2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
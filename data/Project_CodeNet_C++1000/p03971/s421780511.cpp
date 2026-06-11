#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;

    cin >> n >> a >> b;
    string s;
    cin >> s;

    int total = 0;
    int overseas = 0;
    for (int i = 0; i < n; i++)
    {
        if (total >= a+b || s[i] == 'c') cout << "No" << '\n';
        else if (s[i] == 'a')
        {
            total++;
            cout << "Yes" << '\n';
        }
        else if (s[i] == 'b')
        {
            if (overseas < b)
            {
                cout << "Yes" << '\n';
                overseas++;
                total++;
            }
            else cout << "No" << '\n';
        }
    }
    return 0;
}

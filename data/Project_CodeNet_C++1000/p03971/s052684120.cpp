#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    int answer = a + b;
    int all = 0;
    int bppl = 0;
    int ok = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            if (all < answer)
            {
                cout << "Yes" << endl;
                all++;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        if (s[i] == 'b')
        {
            ok++;
            if (all < answer && ok <= b)
            {
                cout << "Yes" << endl;
                all++;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        if (s[i] == 'c')
        {
            cout << "No" << endl;
        }
    }
}
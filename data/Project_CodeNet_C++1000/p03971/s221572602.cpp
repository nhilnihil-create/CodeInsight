#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, a, b;

    cin >> n >> a >> b;
    int max = a + b;
    string s;
    cin >> s;
    int pass = 0;
    int b_count = 0;
    for (char a : s)
    {
        if (a == 'b')
            b_count++;
        if (a == 'a' && pass < max)
        {
            cout << "Yes" << endl;
            pass++;
            continue;
        }
        if (a == 'b' && pass < max && b_count <= b)
        {
            cout << "Yes" << endl;
            pass++;
            continue;
        }
        cout << "No" << endl;
    }
}

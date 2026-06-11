#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int rcount = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'g')
            rcount++;
    }
    cout << rcount - n / 2 - n % 2 << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    char s[n];
    int c = 0, cc = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        if(s[i]=='I')
        {
            cc++;
            c = max(c, cc);
        }
        else
        {
            cc--;
            c = max(c,cc);
        }
    }
    cout << c << endl;
    return 0;
}
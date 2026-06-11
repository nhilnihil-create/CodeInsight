#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int l = 0, r = 0, n = s.size();
    int i = 0;
    while (s[i] == 'B')
        ++l, ++i, ++r;
    while(i < n)
    {
        if ((s[i] == '0' || s[i] == '1'))
            s[l] = s[i], ++l;
        else if (s[i] == 'B')
            if(l != 0)
                --l;
        ++i;
    }
    for (int i = r; i < l; ++i)
        cout << s[i];
}


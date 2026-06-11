#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    string search[4] = {"maerd", "remaerd", "esare", "resare"};
    int d = 0, k;
    for (int i = 0; i < s.length();)
    {
        for (int j = 0; j < 4; j++)
        {
            k = 0;
            if (s.substr(i, search[j].length()) == search[j])
            {
                i += search[j].length();
                k++;
                break;
            }
        }
        if (k == 0)
        {
            d++;
            break;
        }
    }
    if (d == 0) cout << "YES";
    else cout << "NO";
}
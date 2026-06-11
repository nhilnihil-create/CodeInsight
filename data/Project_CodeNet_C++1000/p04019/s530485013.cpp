#include <bits/stdc++.h>
using namespace std;

int main() {
    string st;
    cin >> st;

    string res = "Yes";
    int n = 0, w = 0, s = 0, e = 0;
    for (int i = 0; i < st.size(); i++) {
       switch (st.at(i)) {
           case 'N':
               n++;
               break;
           case 'W':
               w++;
               break;
           case 'S':
               s++;
               break;
           case 'E':
               e++;
               break;
           default:
               break;
       }
    }

    if (!((n == 0 && s == 0) || (n != 0 && s != 0))) res = "No";
    if (!((w == 0 && e == 0) || (w != 0 && e != 0))) res = "No";

    cout << res << endl;

    return 0;
}

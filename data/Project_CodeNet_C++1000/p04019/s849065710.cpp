#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    cin >> a;

    int n = 0, w = 0, s = 0, e = 0;
    for (int i = 0, m = a.size(); i < m; i++)
        switch (a.at(i)) {
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
        }
    
    if ((n > 0  && w > 0  && s > 0  && e > 0 )
     || (n > 0  && w == 0 && s > 0  && e == 0)
     || (n == 0 && w > 0  && s == 0 && e > 0 )
     || (n == 0 && w == 0 && s == 0 && e == 0))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
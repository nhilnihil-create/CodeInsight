
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    int sizea = a.size();
    int sizeb = b.size();
    int sizec = c.size();
    if (a[sizea - 1] == b[0] && b[sizeb - 1] == c[0])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
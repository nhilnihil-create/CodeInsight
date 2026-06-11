#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, res1, res2;
    cin >> a >> b >> c;
    res1 = abs(a-b);
    res2 = abs(a-c);
    if(res1 <= res2) cout << "A" << endl;
    else cout << "B" << endl;
    return 0;
}
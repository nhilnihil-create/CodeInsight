#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    set<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    cout << s.size();

    return 0;
}

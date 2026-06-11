#include <iostream>
#include <string>
#include <set>
using namespace std;

void solve()
{
    int a, b, c;
    set<int> d;
    cin >> a >> b >> c;
    d.insert(a);
    d.insert(b);
    d.insert(c);
    cout  << d.size() << endl;
}

int main()
{
    solve();
    return 0;
}
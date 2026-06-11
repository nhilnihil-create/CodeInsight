#include <bits/stdc++.h>
using namespace std;

int main( )
{
    set<int> a, b, c;
    int x, y;
    a.insert(1);
    a.insert(3);
    a.insert(5);
    a.insert(7);
    a.insert(8);
    a.insert(10);
    a.insert(12);
    b.insert(4);
    b.insert(6);
    b.insert(9);
    b.insert(11);
    c.insert(2);

    cin >> x >> y;
    if ( a.find(x) != a.end() && a.find(y) != a.end() ) {
        cout << "Yes\n";
    }
    else if ( b.find(x) != b.end() && b.find(y) != b.end() ) {
        cout << "Yes\n";
    }
    else if ( c.find(x) != c.end() && c.find(y) != c.end() ) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}

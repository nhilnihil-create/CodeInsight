#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y;
    cin >> x >> y;

    if(x == y) cout << "Draw" << endl;
    else if(x>y && y != 1) cout << "Alice" << endl;
    else if(x>y && y == 1) cout << "Bob" << endl;
    else if(y>x && x != 1) cout << "Bob" << endl;
    else if(y>x && x == 1) cout << "Alice" << endl;

    return 0;
}
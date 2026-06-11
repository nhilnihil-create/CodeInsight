#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    set<int> a = {1, 3, 5, 7, 8, 10, 12};
    set<int> b = {4, 6, 9, 11};
    set<int> c = {2};

    if (a.find(x) != a.end() && a.find(y) != a.end())
        cout << "Yes";
    else if (b.find(x) != b.end() && b.find(y) != b.end())
        cout << "Yes";
    else if (c.find(x) != c.end() && c.find(y) != c.end())
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

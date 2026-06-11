#include<bits/stdc++.h>
using namespace std;
int main () {
    array<int, 12> a{1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
    int x, y;
    cin >> x >> y;
    a[x - 1] == a[y - 1] ? cout << "Yes" : cout << "No";

}

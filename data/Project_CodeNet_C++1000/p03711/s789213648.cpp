#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int x, y;
    vector<int> a{1, 3, 5, 7, 8, 10, 12};
    vector<int> b{4, 6, 9, 11};
    cin >> x >> y;
    if (x == 2 || y == 2) {
        cout << "No";
        return 0;
    }
    if (count(a.begin(), a.end(), x) + count(a.begin(), a.end(), y) == 2) cout << "Yes";
    else if (count(b.begin(), b.end(), x) + count(b.begin(), b.end(), y) == 2) cout << "Yes";
    else cout << "No";

}
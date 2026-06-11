#include <bits/stdc++.h>
using namespace std;

int main() {
    string o, e;
    cin >> o >> e;

    vector<char> v(o.size() + e.size());

    for (int i = 0, n = o.size(); i < n; i++)
        v.at(2 * i) = o.at(i);

    for (int i = 0, n = e.size(); i < n; i++)
        v.at(2 * i + 1) = e.at(i);
    
    string p(v.begin(), v.end());

    cout << p << endl;
}
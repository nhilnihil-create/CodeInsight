#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    list<char> lst;
    for (int i = 0; i < s.size(); ++i) {
        lst.push_back(s[i]);
    }

    
    auto it = lst.begin();
    ++it;
    ++it;
    ++it;
    ++it;
    lst.insert(it, ' ');

    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it;
    }
    cout << endl;
    return 0;
}

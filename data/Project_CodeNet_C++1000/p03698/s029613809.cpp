#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    set<char> st;
    for (char c : s) st.insert(c);
    cout << (s.size() == st.size() ? "yes" : "no") << endl;
}

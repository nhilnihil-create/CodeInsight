#include <bits/stdc++.h>
#include <boost/range/irange.hpp>

using namespace std;
using boost::irange;

int main() {
    string st; cin >> st;
    for (int i : irange(0, (int)st.size(), 2)) {
        cout << st[i];
    }
    cout << endl;
}

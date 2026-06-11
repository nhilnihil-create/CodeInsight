#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int i = s.size() - 1;
    string t;
    while(i >= 0) {
        t.push_back(s[i]);
        if (t == "maerd" || t == "remaerd" || t == "esare" || t ==  "resare")
            t.clear();
        --i;
    }
    if (t.empty())
        cout << "YES";
    else
        cout << "NO";

}

int main() {

    solve();
    return 0;
}

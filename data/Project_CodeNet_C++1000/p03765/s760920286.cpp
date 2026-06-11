#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> x(s.size() + 1);
    for (int i = 0; i < s.size(); i++)x[i + 1] = x[i] + (s[i] == 'A' ? 1 : 2);
    string t;
    cin >> t;
    vector<int> y(t.size() + 1);
    for (int i = 0; i < t.size(); i++)y[i + 1] = y[i] + (t[i] == 'A' ? 1 : 2);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (((x[b] - x[a - 1]) - (y[d] - y[c - 1])) % 3 == 0 ? "YES" : "NO") << endl;
    }
    return 0;
}
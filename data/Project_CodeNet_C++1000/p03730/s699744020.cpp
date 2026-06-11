#include <bits/stdc++.h>
using namespace std;

int main() {

// ax = by + c;
// ax - by = c;

int a, b, c;

cin >> a >> b >> c;

vector<int> list(b);
string answer = "NO";
for (int i = 1; i <= b; i++) {
    int mod = (i * a) % b;
    if (c == mod) {
        answer = "YES";
    }
    if (list.at(mod) == 0) {
        list.at(mod) = 1;
    } else {
        break;
    }
}

cout << answer << endl;

return 0;
}
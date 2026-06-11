#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mi = 0, now = 0;
    for (int i = 0; i < n; i++) {
        now += s[i] == '(' ? 1 : -1;
        mi = min(mi, now);
    }

    cout << string(-mi, '(') << s << string(now - mi, ')') << endl;
    return 0;
}
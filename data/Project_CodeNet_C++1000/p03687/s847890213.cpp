#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int ans = s.size();
    for (char c = 'a'; c <= 'z'; c++) {
        string t = s;
        int same = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == c) same++;
        }
        int cnt = 0;
        while (same != t.size()) {
            same = 0;
            cnt++;
            string str;
            for (int i = 0; i < t.size() - 1; i++) {
                if (t[i] == c || t[i+1] == c) {
                    str += c;
                    same++;
                } else {
                    str += t[i];
                }
            }
            t = str;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}
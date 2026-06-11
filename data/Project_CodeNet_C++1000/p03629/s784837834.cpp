#include <bits/stdc++.h>
using namespace std;
using Int = long long;
struct strview {
    const char *ptr;
    int sz;
    strview(const char* p, int s) : ptr(p), sz(s) {}
    const char& operator[](int x) { return ptr[x]; }
    int size() { return sz; }
    strview substr(int pos, int count) { return strview(ptr+pos, count); }
};
int main()
{
    string A; cin >> A;
    strview s(A.c_str(), A.size());
    string ans;
    for (;;) {
        int counter = 0, letters = 0;
        for (int i = s.size()-1; i >= 0; i--) {
            letters |= 1 << (s[i]-'a');
            if (letters == (1 << 26)-1) {
                counter++;
                letters = 0;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (!(letters & (1 << i))) {
                ans.push_back('a' + i);
                break;
            }
        }
        if (counter == 0) break;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ans.back()) {
                s = strview(&s[i+1], s.size() - i - 1);
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

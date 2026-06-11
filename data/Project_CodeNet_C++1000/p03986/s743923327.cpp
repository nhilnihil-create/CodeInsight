#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt_s = 0;
    int del_n = 0;
    for (int i=0; i<s.size(); ++i) {
        if (cnt_s) {
            if (s[i] == 'S') cnt_s++;
            else {
                del_n += 2;
                cnt_s--;
            }
        }
        else {
            if (s[i] == 'S') cnt_s++;
        }
    }
    int ans = s.size() - del_n;
    cout << ans << endl;
}
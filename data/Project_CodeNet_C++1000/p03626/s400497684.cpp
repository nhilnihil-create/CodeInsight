#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
int main() {
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    int i = 0;
    ll ret = 1;
    int mark = 0;
    //0: 空白   1: 横横  2: 縦
    while (i < n) {
        if ((i + 1 < n)&&(s1[i] == s1[i + 1])) {
            if (mark == 0) {
                ret *= 6;
            }
            else if (mark == 1) {
                ret *= 3;
            }
            else {
                ret *= 2;
            }
            i += 2;
            mark = 1;
        }
        else {
            if (mark == 0) {
                ret *= 3;
            }
            else if (mark == 1) {
                ret *= 1;
            }
            else {
                ret *= 2;
            }
            i++;
            mark = 2;
        }
        ret %= mod;
    }
    cout << ret << endl;
    return 0;
}
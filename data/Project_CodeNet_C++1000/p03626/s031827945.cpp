#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string s, t;
    cin >> s;
    cin >> t;
    long int ans = 1;
    long int mod = 1000000007;
    bool pre = true; //trueで縦
    for (int i = 0; i < N; i++) {
        if (i == 0){
            if (s[0] == t[0]) ans = 3;
            else {
                ans = 6;
                i++;
                pre = false;
            }
            continue;
        }
        if (pre) {
            if (s[i] == t[i]) {
                ans *= 2;
                pre = true;
            }
            else {
                ans *= 2;
                i++;
                pre = false;
            }
            ans %= mod;
        }
        else {
            if (s[i] == t[i]) {
                pre = true;
            }
            else {
                ans *= 3;
                i++;
                pre = false;
            }
            ans %= mod;
        }
    }
    cout << ans << endl;
}
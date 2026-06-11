#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    priority_queue<int, vector<int>, greater<int>> ans;
    bool same = true;
    rep(i, s.size()-1) {
        if (s[i] != s[i+1]){
            same = false;
            break;
        }
    }
    if (same) {
        cout << 0 << endl;
        return 0;
    }
    for (char i = 'a'; i <= 'z'; i++) {
        int count = 0;
        string t = s;
        while (t.size() > 0) {
            string nt;
            bool check = true;
            rep(j, t.size()-1) {
                if (t[j] == i || t[j+1] == i) {
                    nt += i;
                }
                else {
                    nt += t[j];
                    check = false;
                }
            }
            count++;
            t = nt;
            if (check) {
                break;
            }
        }
        ans.push(count);
    }
    cout << ans.top() << endl;
}
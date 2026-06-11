#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

pair<bool, string> check(char f, char sec, string s) {
    int n = s.size();
    string ans = s;
    ans[0] = f;
    ans[1] = sec;
    for(int i = 1; i < n; i++) {
        if (ans[i] == 'S') {
            if (s[i] == 'o') {
                ans[(i+1)%n] = ans[i-1];
            } else {
                ans[(i+1)%n] = (ans[i-1]=='W') ? 'S' : 'W';
            }
        } else { // WALF
            if (s[i] == 'x') {
                ans[(i+1)%n] = ans[i-1];
            } else {
                ans[(i+1)%n] = (ans[i-1]=='W') ? 'S' : 'W';
            }

        }
    }

    if (ans[0] != f) {
        return {false, ans};
    } else {
        bool species = (ans[0] == 'S') ? true : false;
        bool tell = (s[0] == 'o') ? true : false;
        bool neibor = (ans[n-1] == ans[1]);
        //cout << species << " " << tell << " " << neibor << endl;
        //cout << "f = " << f << ", s = " << sec << endl;
        //cout << "last "  << (species^tell^neibor) << endl;
        return {species^tell^neibor, ans};
    }
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    auto res1 = check('S', 'W', s);
    if (res1.first) {
        cout << res1.second << endl;
        return 0;
    }
    res1 = check('W', 'S', s);
    if (res1.first) {
        cout << res1.second << endl;
        return 0;
    }
    res1 = check('W', 'W', s);
    if (res1.first) {
        cout << res1.second << endl;
        return 0;
    }
    res1 = check('S', 'S', s);
    if (res1.first) {
        cout << res1.second << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}



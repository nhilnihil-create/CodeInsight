#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    if(n == 2 && s[0] == s[1]){
        cout << "1 2" << endl;
        return 0;
    }
    rep(i, n - 2){
        if(s[i]==s[i+1]||s[i+1]==s[i+2]||s[i]==s[i+2]){
            cout << i + 1 << ' ' << i + 3 << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;
}
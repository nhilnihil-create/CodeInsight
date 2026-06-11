#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    string s, t;
    cin >> s >> t;
    int n = min(s.size(), t.size());
    if (s.size() - t.size() == 1) {
        for (int i = 0; i < n; i++) {
            cout << s[i] << t[i];
        }
        cout << s[n];
    }
    else{
        for (int i = 0; i < n; i++) {
            cout << s[i] << t[i];
        }
    }
    cout << endl;

    return 0;
}
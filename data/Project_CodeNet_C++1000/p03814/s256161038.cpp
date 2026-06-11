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
    string s;
    cin >> s;
    int a, b;
    rep(i, s.size()) {
        if(s[i] =='A') {
            a = i;
            break;
        }
    }
    for(int i = s.size(); i >= 0; i--) {
        if(s[i] == 'Z') {
            b = i + 1;
            break;
        }
    }
    cout << b - a << endl;

    return 0;
}
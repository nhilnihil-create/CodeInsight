#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    string t = s;

    reverse(t.begin(), t.end());

    rep(i, t.size()) {
        if(t[i] == 'b') {
            t[i] = 'd';
        }
        else if(t[i] == 'd') {
            t[i] = 'b';
        }
        else if(t[i] == 'p') {
            t[i] = 'q';
        }
        else if(t[i] == 'q') {
            t[i] = 'p';
        }
    }

    if(t == s) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    cout << endl;
    return 0;
}
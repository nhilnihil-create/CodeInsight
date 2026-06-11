#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    string s;
    cin >> s;
    if ( s.length() < 4 ) {
        cout << "No" << endl;
        return 0;
    }
    string s_req = "YAKI";
    rep(i, 4) {
        if ( s[i] == s_req[i] ) continue;
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

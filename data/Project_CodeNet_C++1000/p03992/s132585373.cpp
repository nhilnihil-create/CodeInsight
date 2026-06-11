#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    rep(i, s.length()) {
        if ( i == 3 ) {
            cout << s[i] << " ";
        }
        else {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}

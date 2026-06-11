#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

int main (){
    string s;
    cin >> s;

    bool ok = false;
    if(s[0] == '9' || s[1] == '9'){
        ok = true;
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
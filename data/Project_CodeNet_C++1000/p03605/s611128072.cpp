#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    bool ans = false;
    for(int i = 0; i<3; i++){
        if(s[i] == '9') ans =true;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
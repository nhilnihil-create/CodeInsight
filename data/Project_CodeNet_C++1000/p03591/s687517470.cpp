#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    if (s.size() < 4){
        cout << "No" << endl;
        return 0;
    }
    bool flag = true;
    string yaki = "YAKI";
    for (int i = 0; i < 4; i++){
        if (s[i] != yaki[i]) flag = false;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
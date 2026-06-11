#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '9'){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s;
    cin >> s;
    
    for (long unsigned int i=0; i<s.length()-2; i++){
        if (s[i] == s[i+1]){
            cout << i+1 << " " << i+2;
            return 0;
        }
        if (s[i] == s[i+2]){
            cout << i+1 << " " << i+3;
            return 0;
        }
    }
    
    if (s[s.length()-2] == s[s.length()-1]){
        cout << s.length()-1 << "  " << s.length();
    }
    else{
        cout << "-1 -1";
    }
    
    return 0;   
}
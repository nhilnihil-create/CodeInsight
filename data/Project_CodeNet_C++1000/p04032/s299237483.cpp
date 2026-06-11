#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

const int mod = 1e9+7;

string s;

int main(){
    cin >> s;
    for(int i = 0; i+1 < s.size(); i++){
        if(s[i] == s[i + 1]){
            cout << i+1 << " " << i + 2 << "\n";
            return 0;
        }
    }
    for(int i = 0; i+2 < s.size(); i++){
        if(s[i] == s[i + 2]){
            cout << i+1 << " " << i + 3 << "\n";
            return 0;
        }
    }
    cout << -1 << " " << -1 << "\n";
}
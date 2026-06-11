#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    int ans;
    cin >> s;
    while(s.length() != 1){
        s.pop_back();
        ans = s.length();
        if(s.substr(0,s.length()/2) == s.substr(s.length()/2)) break;
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < s.size(); i+=2){
        ans = ans + s[i];
    }
    
    cout << ans << endl;
}

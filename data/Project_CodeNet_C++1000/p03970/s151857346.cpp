#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s, str = "CODEFESTIVAL2016";
    int ans = 0;
    cin >> s;
    for (int i=0; i<16; i++){
        if (s[i] != str[i]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
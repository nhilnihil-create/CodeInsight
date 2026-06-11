#include<bits/stdc++.h>
using namespace std;

int main(){
    char s[17],t[17] = "CODEFESTIVAL2016";
    cin >> s;
    int ans = 0;
    for(int i = 0;i < 17;i++){
        if(s[i] != t[i])++ans;
    }
    cout << ans << endl;
}
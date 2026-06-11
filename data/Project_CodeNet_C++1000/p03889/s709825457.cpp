#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
string s, t;
int main(){
    ios::sync_with_stdio(false);
    cin >> s;
    t = s;
    reverse(s.begin(), s.end());
    for(int i = 0; i < (int)s.size(); ++i){
        if(s[i] == 98) s[i] = 100;
        else if(s[i] == 100) s[i] = 98;
        else if(s[i] == 112) s[i] = 113;
        else if(s[i] == 113) s[i] = 112;
    }
    if(s == t) cout << (char)89 << (char)101 << (char)115;
    else cout << (char)78 << (char)111;
    return 0;
}
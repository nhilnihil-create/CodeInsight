#include <bits/stdc++.h>

using namespace std;

bool allA(string s){
    for(char c : s){
        if(c != 'a')return false;
    }
    return true;
}

int main() {
    string s ; cin>>s;
    int n ; cin>>n;
    int m = s.size();
    for(int i = 0 ; i < m; ++i){
        int pos = s[i] - 'a';
        if(26 - pos <= n && s[i] != 'a'){
            n -= (26 - pos);
            s[i] = 'a';
        }
    }
    if(allA(s)){
        int norm = n % 26;
        while(norm--){
            s[m - 1] = char(s[m - 1] + 1);
        }
        cout<<s<<"\n";
        return 0;
    }
    int norm = n % 26;
    for(;norm--;){
        s[m - 1]++;
        if(s[m - 1] > 'z')s[m - 1] = 'a';
    }
    cout<<s<<"\n";
}

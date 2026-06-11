#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    reverse(s.begin(), s.end());
    ll itr = 0;
    bool f = true;
    while(itr < n && f){
        if(s[itr] == 'm') {
            if(s.substr(itr, 5) != "maerd") f = false;
            itr += 5;
        } else if (s[itr] == 'e') {
            if(s.substr(itr, 5) != "esare") f = false;
            itr += 5;
        } else if (s[itr] == 'r') {
            if(s.substr(itr, 6) == "resare") itr += 6; 
            else if(s.substr(itr, 7) == "remaerd") itr += 7; 
            else f = false;
        }
    }
    if(itr != n) f = false;
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
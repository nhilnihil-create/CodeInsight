#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    string s, t, save;
    cin >> s;
    reverse(s.begin(), s.end());
    for(char &c : s){
        save += c;
        if(save=="maerd"||save=="remaerd"||save=="esare"||save=="resare"){
            t += save;
            save = "";
        }
    }
    if(s == t) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
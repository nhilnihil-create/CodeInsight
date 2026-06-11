#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;

    vector<int> c(26);
 
    for(int i=0;i<s.size();i++){
        c.at((int)s.at(i)-(int)'a')++;
    }

    string ans = "None";

    for(int i=0;i<26;i++){
        if(c.at(i)==0){
            ans = (char)((int)'a'+i);
            break;
        }
    }

    cout << ans <<endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int i;
    string s, ans="";
    cin >> s;
    for(i=0;i<s.size();i++){
        if(s[i]=='B' && !ans.empty()) ans.pop_back();
        else if(s[i]!='B') ans+=s[i];
    }

    cout << ans << endl;
    return 0;
}
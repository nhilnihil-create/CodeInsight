#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,ans = "";
    cin >> s;
    for(int ix;ix<s.size();ix++){
        if(s.at(ix) == '0') ans += "0";
        if(s.at(ix) == '1') ans += "1";
        if(s.at(ix) == 'B' && !ans.empty()) ans.erase(ans.end()-1);
    }
    cout << ans << endl;
}
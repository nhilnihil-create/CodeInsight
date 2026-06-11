#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0') ans += '0';
        else if(s[i] == '1') ans += '1';
        else if(ans != "") ans.pop_back();
    }
    cout << ans << endl;
    return 0;
}
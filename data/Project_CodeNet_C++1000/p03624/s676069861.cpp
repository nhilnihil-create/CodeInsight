#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<bool> isexist(26, false);
    for(int i = 0; i < s.length(); i++) isexist[s[i]-'a'] = true;
    string ans = "None";
    for(int i = 0; i < 26; i++){
        if(!isexist[i]){
            ans = (i+'a');
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
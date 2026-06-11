#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> backet(26, 0);
    for(int i = 0; i < s.length(); i++){
        backet[s[i]-'a']++;
    }
    string ans = "yes";
    for(int i = 0; i < 26; i++){
        if(backet[i] >= 2) ans = "no";
    }
    cout << ans << endl;
    return 0;
}
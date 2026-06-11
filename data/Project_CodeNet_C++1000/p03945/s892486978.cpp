#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;cin >> s;
    auto pre = s[0];
    auto ans = 0;

    for (auto i = 1; i < s.length(); ++i) {
        if (pre != s[i]){
            ans += 1;
            pre = s[i];
        }
    } 
    cout << ans << endl;

}
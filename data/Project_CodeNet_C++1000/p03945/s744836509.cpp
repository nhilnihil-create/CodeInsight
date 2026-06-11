#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;cin >> s;
    auto pre = s.at(0);
    auto ans = 0;

    for (auto i = 1; i < s.size(); ++i) {
        if (pre != s.at(i)){
            ans += 1;
            pre = s.at(i);
        }
    } 
    cout << ans << endl;

}
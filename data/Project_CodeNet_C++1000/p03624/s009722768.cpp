#include <iostream>
#include <string>
#include <map>

int main () {
    std::string str, alpha = "abcdefghijklmnopqrstuvwxyz", ans = "None";
    std::cin >> str;
    std::map<char, int> m;
    for(int i = 0; i < 26; ++i){
        m.insert(std::make_pair(alpha[i], 0));
    }
    for(int i = 0; i < str.length(); ++i){
        ++m[str[i]];
    }
    for(int i = 0; i < 26; ++i){
        if(m[alpha[i]]==0) {
            ans = alpha[i];
            break;
        }
    }
    std::cout << ans << std::endl;
}

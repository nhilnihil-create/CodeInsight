#include <iostream>
#include <map>

int main(void){
    std::string S, ans="yes";
    std::cin >> S;
    std::map<char, int> mp;
    for (char c: S){
        if (mp.find(c) == mp.end()){
            mp[c] = 0;
        } else {
            ans = "no";
            break;
        }
    }

    std::cout << ans << std::endl;
    
    return 0;
}

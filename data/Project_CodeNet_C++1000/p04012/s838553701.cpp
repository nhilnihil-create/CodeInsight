#include <iostream>
#include <map>

int main(void){
    std::string w, ans="Yes";
    std::cin >> w;
    std::map<char, int> mp;

    for (char c: w){
        if (mp.find(c) == mp.end()){
            mp[c] = 1;
        } else {
            ++mp[c];
        }
    }

    for (auto& x: mp){
        if (x.second % 2 == 1){
            ans = "No";
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

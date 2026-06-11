#include <iostream>
#include <map>

int main(void){
    std::map<char, int> mp;
    mp['N'] = 0;
    mp['S'] = 0;
    mp['E'] = 0;
    mp['W'] = 0;
    std::string S, ans="No";
    std::cin >> S;

    for (char c: S){
        ++mp[c];
    }

    if ((mp['N'] == 0 && mp['S'] == 0) || (mp['N'] > 0 && mp['S'] > 0)){
        if((mp['E'] == 0 && mp['W'] == 0) || (mp['E'] > 0 && mp['W'] > 0)){
            ans = "Yes";
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

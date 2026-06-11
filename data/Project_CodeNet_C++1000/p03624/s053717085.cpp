#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main() {
    std::string s;
    std::cin >> s;

    std::string ans = "None";
    for (int i = 'a'; i <= 'z'; i++) {
        bool f = false;
        for (int j = 0; j < s.size(); j++)
        {
            if(i == s[j]) {
                f = true;
            }
        }
        if(!f) {
            ans = i;
            break;
        }
    }

    std::cout << ans << "\n";
}
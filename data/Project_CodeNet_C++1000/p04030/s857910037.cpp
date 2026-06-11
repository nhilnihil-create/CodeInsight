#include<iostream>
#include<string>

int main() {
    std::string s;
    std::cin >> s;

    char ans[20];
    int index = 0;
    for (int i = 0; i < s.size(); i++) {
        if(s[i] != 'B') {
            ans[index++] = s[i];
        } else if(index != 0) {
            index--;
        }
    }

    ans[index] = '\0';

    std::cout << ans << "\n";
}
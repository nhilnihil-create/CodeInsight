#include<iostream>
#include<string>
#include<set>
int main() {
    std::string s;
    std::cin >> s;
    std::set<int> ss;
    for (int i = 0; i < s.size(); i++)
    {
        ss.insert(s[i]);
    }

    std::string ans = ss.size() == s.size() ? "yes" : "no";

    std::cout << ans << "\n";
}
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::pair<int, int>> d(26, std::pair<int, int>(0, 0));
    std::string s; std::cin >> s;
    for (int i = 0; i < (int)s.size(); i++){
        int cc = s[i] - 'a';
        auto& dd = d[cc];
        dd.second = std::max(dd.second, i - dd.first);
        dd.first = i+1;
    }
    for (auto& dd: d) {
        dd.second = std::max(dd.second, (int)s.size() - dd.first);
    }
    /*
    for (int i = 'a'; i < 'z'; i++) {
        const auto dd = d[i - 'a'];
        if (dd.second < s.size()) {
            std::cout << (char)i << " " << dd.second << std::endl;
        }
    }
    */
    std::sort(d.begin(), d.end(), [](const auto& a, const auto& b){
        return a.second < b.second;
    });

    std::cout << d[0].second << std::endl;
    return 0;
}
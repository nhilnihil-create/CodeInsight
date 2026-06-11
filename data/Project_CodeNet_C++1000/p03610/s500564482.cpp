#include <iostream>
#include <vector>

int main(int argc, char **argv)
{

    std::string s;
    std::cin >> s;

    std::vector<char> ans;
    for(int i = 0; i < s.size(); i++){
        if(i % 2 == 0) ans.push_back(s.at(i));
    }

    std::string ss(ans.begin(), ans.end());
    std::cout << ss << std::endl;
}

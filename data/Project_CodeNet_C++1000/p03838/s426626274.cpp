#include<iostream>
#include<vector>
#include<algorithm>

int main(){

    int x, y;
    std::cin >> x >> y;

    std::vector<size_t> ans;

    if(x  <= y)  ans.emplace_back(y - x);
    if(-x <= y)  ans.emplace_back(y + x + 1);
    if(x  <= -y) ans.emplace_back(-y - x + 1);
    if(-x <= -y) ans.emplace_back(-y + x + 2);

    std::cout << *std::min_element(ans.begin(), ans.end()) << std::endl;

    return 0;
}

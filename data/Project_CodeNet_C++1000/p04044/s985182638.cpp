#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

int main(void){
    int n, l;
    std::cin >> n >> l;
    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> ss;
    for(int i = 0; i < n; ++i){
        std::string s;
        std::cin >> s;
        ss.push(s);
    }
    while(!ss.empty()){
        std::cout << ss.top();
        ss.pop();
    }
    std::cout << std::endl;

    return 0;
}
#include<iostream>
#include<vector>
#include<utility>

int main(){

    size_t n;
    std::cin >> n;

    std::vector<std::pair<size_t, size_t>> ab(n);

    for(auto&& e : ab){
        std::cin >> e.first >> e.second;
    }

    size_t cnt = 0;
    for(size_t i = 0; i < n; i++){
        if((ab.at(n - i - 1).first + cnt) % ab.at(n - i - 1).second != 0){
            cnt += ab.at(n - i - 1).second - ((ab.at(n - i - 1).first + cnt) % ab.at(n - i - 1).second);
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}

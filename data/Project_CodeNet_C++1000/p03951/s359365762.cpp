#include<iostream>
#include<string>
#include<algorithm>

int main(){

    size_t n;
    std::string s, t;
    std::cin >> n >> s >> t;

    if(s == t){
        std::cout << n << std::endl;
    }else if(s.back() == t.front()){
        size_t cnt1 = 0;
        for(size_t i = 0; i < n; i++){
            if(s.at(n - i - 1) == s.back()){
                cnt1++;
            }else{
                break;
            }
        }

        size_t cnt2 = 0;
        for(size_t i = 0; i < n; i++){
            if(t.at(i) == t.front()){
                cnt2++;
            }else{
                break;
            }
        }

        std::cout << 2 * n - std::min(cnt1, cnt2) << std::endl;
    }else{
        size_t min = std::numeric_limits<size_t>::max();
        for(size_t i = 0; i < n; i++){
            auto str = s.substr(0, n - i) + t.substr(i, n);
            if((str.find(s) != std::string::npos) && (str.find(t) != std::string::npos)){
                min = std::min(min, str.size());
            }
        }

        std::cout << min << std::endl;
    }

    return 0;
}

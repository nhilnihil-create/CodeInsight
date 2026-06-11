#include<iostream>
#include<string>
#include<algorithm>
#include<map>

int main(){

    std::string s;
    std::cin >> s;

    std::map<char, size_t> m;

    for(size_t i = 0; i < s.size(); i++){
        if(m.find(s[i]) != m.end()){
            m[s[i]]++;
        }else{
            m.emplace(s[i], 1);
        }
    }

    size_t min = s.size();
    for(const auto& e : m){
        std::string prev = s;
        char goal = e.first;
        while(!std::all_of(prev.begin(), prev.end(), [goal](char c){ return c == goal; })){
            std::string next(prev.size() - 1, ' ');
            for(size_t i = 0; i < next.size(); i++){
                if(prev[i] == goal || prev[i + 1] == goal){
                    next[i] = e.first;
                }else{
                    next[i] = prev[i];
                }
            }

            prev = next;
        }

        min = std::min(min, s.size() - prev.size());
    }

    std::cout << min << std::endl;

    return 0;
}
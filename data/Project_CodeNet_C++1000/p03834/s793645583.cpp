#include <string>
#include <iostream>

int main(){
    std::string s;
    std::cin >> s;
    int n = s.size();
    for(int i = 0; i < n; ++i){
        if(i == 5 || i == 13) std::cout << ' '; 
        else std::cout << s[i];
    }
    std::cout << std::endl;
}
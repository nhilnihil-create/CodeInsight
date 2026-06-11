#include<iostream>
#include<string>

int main(){
    std::string N;
    std::cin >> N;
    if(N[0] == '9' || N[1] == '9'){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
    return 0;
}

#include<iostream>
#include<string>

int main(){
    std::string S[3];
    for(int i = 0; i < 3; i++){
        std::cin >> S[i];
    }
    if((S[0][S[0].size() - 1] == S[1][0])
        && (S[1][S[1].size() - 1] == S[2][0])){
            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    return 0;
}

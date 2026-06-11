#include<iostream>
#include<vector>
#include<string>

int main(){
    std::string S;
    std::cin >> S;
    int cnt = 0;
    char c = S[0];
    for(int i = 1; i < S.size(); i++){
        if(c != S[i]){
            cnt++;
            c = S[i];
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}

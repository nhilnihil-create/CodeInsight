#include<iostream>
#include<vector>
#include<string>

std::string eraser = "eraser";
std::string erase = "erase";
std::string dream = "dream";
std::string dreamer = "dreamer";

int main(){
    std::string S;
    std::cin >> S;

    // eraserの削除
    std::string::size_type npos = S.find(eraser, 0);
    while(npos != std::string::npos){
        S.erase(npos, eraser.size());
        npos = S.find(eraser, npos);
    }

    // eraseの削除
    npos = S.find(erase, 0);
    while(npos != std::string::npos){
        S.erase(npos, erase.size());
        npos = S.find(erase, npos);
    }

    // 残りがdreamとdreamerのみであることを確認
    npos = S.find(dreamer, 0);
    while(npos != std::string::npos){
        S.erase(npos, dreamer.size());
        npos = S.find(dreamer, npos);
    }

    npos = S.find(dream, 0);
    while(npos != std::string::npos){
        S.erase(npos, dream.size());
        npos = S.find(dream, npos);
    }

    if(S.empty()){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}

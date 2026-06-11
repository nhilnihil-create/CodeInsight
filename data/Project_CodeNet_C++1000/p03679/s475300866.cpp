#include<iostream>

int main(){
    int X, A, B;
    std::cin >> X >> A >> B;
    if(A >= B){
        std::cout << "delicious" << std::endl;
    }else{
        if(A + X >= B){
            std::cout << "safe" << std::endl;
        }else{
            std::cout << "dangerous" << std::endl;
        }
    }
    return 0;
}

#include<iostream>

int main(){
    int A, B;
    std::cin >> A >> B;
    if(A + B >= 24){
        std::cout << A + B - 24 << std::endl;
    }else{
        std::cout << A + B << std::endl;
    }
    return 0;
}

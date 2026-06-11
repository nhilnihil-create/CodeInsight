#include<iostream>

int main(){
    int A, B;
    std::cin >> A >> B;
    if(A * B * (A + B) % 3 == 0){
        std::cout << "Possible" << std::endl;
    }else{
        std::cout << "Impossible" << std::endl;
    }
    return 0;
}

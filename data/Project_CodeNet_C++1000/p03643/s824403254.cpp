#include<iostream>

int main(){
    int N;
    std::cin >> N;
    int keta[3];
    for(int i = 0; i < 3; i++){
        keta[i] = N % 10;
        N /= 10;
    }

    int val = keta[0] + keta[1] * 10 + keta[2] * 100;
    std::cout << "ABC" << val << std::endl;
    return 0;
}

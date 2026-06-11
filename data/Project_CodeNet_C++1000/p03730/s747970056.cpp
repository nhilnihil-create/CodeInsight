#include <iostream>

int main() {
    int A,B,C;
    std::cin >> A >> B >> C;

    int base = C % A;
    int amari;
    int i=1;
    bool ok =false;
    do{
        amari = (B*i + C ) % A;
        i++;
        if(amari == 0){
            ok = true;
        }
    }
    while(amari != 0 && amari != base);

    if(ok){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    return 0;
}
#include <iostream>

int main(void){
    int d;
    std::string O, E;
    std::cin >> O >> E;
    d = O.size() - E.size();

    for (int i=0; i<O.size(); ++i){
        if (d == 1 && i == E.size()){
            std::cout << O.at(i);
        } else {
            std::cout << O.at(i) << E.at(i);
        }
    }

    std::cout << std::endl;

    return 0;
}

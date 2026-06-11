#include<iostream>
int main(){
    int X, A, B;
    std::cin >> X >> A >> B;
    if(B - A <= 0) std::cout <<"delicious";
    else if(B - A > X) std::cout << "dangerous";
    else std::cout<<"safe";
}
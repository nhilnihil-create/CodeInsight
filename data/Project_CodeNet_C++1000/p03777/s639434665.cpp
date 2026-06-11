#include<iostream>
int main(){
    char a, b;
    std::cin >> a >> b;
    if(a == 'H') std::cout<< (b=='H' ? 'H' : 'D');
    else std::cout << (b=='H' ? 'D' : 'H');
}
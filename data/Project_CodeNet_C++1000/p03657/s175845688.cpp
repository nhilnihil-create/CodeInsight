#include<iostream>
int main(){int A,B;std::cin>>A>>B;puts(A%3*B%3*(A+B)%3?"Impossible":"Possible");}
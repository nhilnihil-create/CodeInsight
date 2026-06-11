#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>

int main(){
    boost::multiprecision::cpp_int A,B;
    std::cin>>A>>B;
    if(A>B)std::cout<<"GREATER";
    else if(A<B)std::cout<<"LESS";
    else std::cout<<"EQUAL";
}

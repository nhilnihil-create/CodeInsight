#include <iostream>
int main(){
  int A,B; std::cin>>A>>B; A+=13*(A==1); B+=13*(B==1);
  std::cout<<(A==B?"Draw":(A>B?"Alice":"Bob"));
}
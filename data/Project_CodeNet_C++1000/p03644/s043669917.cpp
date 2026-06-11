#include<iostream>

int main(){
int n;
 std::cin >> n;
 int i=1;
 if(n&(n-1)==0)
     std::cout << n << " ";
 else{
 while(1){
  if(1<<i > n){
     std::cout << (1<<i-1) << std::endl;
     break;
  }
  i++;
 }
}
 return 0;
}


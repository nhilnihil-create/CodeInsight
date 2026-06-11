#include <iostream>
#include <cstdio>
#include <algorithm>


int main(void){
  std::string str;
  std::cin >> str;

  std::string temp = str;
  std::reverse(temp.begin(), temp.end());
  std::replace(temp.begin(), temp.end(), 'b', '1');
  std::replace(temp.begin(), temp.end(), 'd', '2');
  std::replace(temp.begin(), temp.end(), 'p', '3');
  std::replace(temp.begin(), temp.end(), 'q', '4');
  std::replace(temp.begin(), temp.end(), '1', 'd');
  std::replace(temp.begin(), temp.end(), '2', 'b');
  std::replace(temp.begin(), temp.end(), '3', 'q');
  std::replace(temp.begin(), temp.end(), '4', 'p');

  if (str == temp) {
    std::cout << "Yes" << std::endl;
  }else{
    std::cout << "No" << std::endl;
  }

  return 0;
}


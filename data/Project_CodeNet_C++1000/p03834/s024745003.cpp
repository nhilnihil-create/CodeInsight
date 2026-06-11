#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  string a;
  cin >> a;
  a.at(5) = ' ';
  a.at(13)= ' ';
  cout  << a;
}

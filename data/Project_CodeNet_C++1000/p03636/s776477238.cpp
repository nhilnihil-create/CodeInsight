#include <iostream>
#include <string>
using namespace std;

int main(){

  string s;
  cin >> s;

  int size = s.size();

  char first = s[0];
  char last = s[size-1];
  int number = size-2;

  cout <<first << number << last<<endl;
 }
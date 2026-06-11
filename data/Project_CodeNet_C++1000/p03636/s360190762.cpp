#include <iostream>
#include <string>
using namespace std;

int main(){
  string S;
  cin >> S;
  int size = S.size();
  string result = S[0] + to_string(size - 2) + S[size - 1];
  cout << result << endl; 
}
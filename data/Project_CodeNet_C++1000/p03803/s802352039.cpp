#include <iostream>
#include <string>
#include <set>
#include <regex>
using namespace std;

int main () {
  int n, m;
  cin >> n >> m;
  n = (n!=1 ? n-1 : 13);
  m = (m!=1 ? m-1 : 13);
  
  cout << (n == m ? "Draw" : (n > m ? "Alice" : "Bob")) << endl;
}
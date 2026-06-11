#include <iostream>
#include <string>

using namespace std;

int const NMAX = 1e5;
int v[1 + NMAX];

int main() {

  int n, pos = 1, p, ans = 1;
  string GUIDO;
  char MISTA;
  while(cin >> MISTA){
    if(ans % 2){
      cout << MISTA;
    }
    ans++;
  }
  return 0;
}

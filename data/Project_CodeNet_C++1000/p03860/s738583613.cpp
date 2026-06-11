#include <iostream>
using namespace std;

int main()
{
  string name;
  char alphabet;

  getline(cin, name);
  alphabet = name[8];

  cout << "A" << alphabet << "C" << endl;
}

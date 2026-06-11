#include <iostream>
#include <string>
using namespace std;

int main()
{
  string o, e;
  cin >> o >> e;
  
  for(unsigned int i = 0; i < e.length(); ++i){
    cout << o[i];
    cout << e[i];
  }
  if(o.length() != e.length()) cout << o.back() << endl;
}
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
  vector<string> v;
  string str, s;

  getline(cin, str);
  stringstream ss{str};

  while( getline(ss, s, ' ') ) {
    v.push_back(s);
  }

  for(string tmp : v) {
    cout << tmp[0];
  }
  cout << endl;
  return(0);
}
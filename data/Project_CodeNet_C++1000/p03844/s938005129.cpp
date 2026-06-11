#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
  string str, s;

  getline(cin, str);
  stringstream ss{str};

  int cnt = 0;
  int a,b;
  string op;
  while( getline(ss, s, ' ') ) {
    if(cnt==0)  a=stoi(s);
    else if(cnt==1)  op=s;
    else b=stoi(s);
    cnt ++;
  }

  if(op == "+")  cout << a + b;
  else cout << a-b;
  cout << endl;

  return(0);
}
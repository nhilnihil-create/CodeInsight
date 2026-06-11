#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int a,b,c;
  string st;
  cin >> a >> st;
  b = a;
  a = 0;
  c = 0;
  for(int i=0;i<b;i++){
    if(st.at(i)=='D') a--;
    else a++;
    c = max(c,a);
  }
  cout << c << endl;
}
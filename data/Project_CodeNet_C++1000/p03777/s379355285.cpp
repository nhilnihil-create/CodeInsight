#include <iostream>

using namespace std;

int main(void){
  char a, b;
  cin >> a >> b;
  bool At_flag, To_flag;

  //At君の真偽性
  if(a == 'H')
    At_flag = true;
  else
    At_flag = false;

  //At君によるTop君の真偽性
  if(b == 'H')
    To_flag = true;
  else
    To_flag = false;

  //この2つのflagでXORをとり，否定をとれば答えが得られる
  bool ans = At_flag ^ To_flag;
  if(ans)
    cout << "D" << endl;
  else
    cout << "H" << endl;
    
  return 0;
}

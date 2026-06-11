#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int counter_5, counter_7;
    counter_5 = 0;
    counter_7 = 0;
    if(a == 5)++counter_5;
    else if(a == 7)++counter_7;
    if(b == 5)++counter_5;
    else if(b == 7)++counter_7;
  if(c == 5)++counter_5;
    else if(c == 7)++counter_7;
  
  if((counter_5 == 2)&&(counter_7 == 1))cout << "YES" << endl;
  else cout << "NO" << endl;
}
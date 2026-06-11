#include <bits/stdc++.h>
using namespace std;

int main(){
  char a,b;
  cin >> a >> b;
  if(a == 'D' && b == 'H'){
    b = 'D';
  }
  else if(a == 'D' && b == 'D'){
    b = 'H';
  }
  printf("%c\n",b);
  return 0;
}

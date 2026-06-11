#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long int x;
  cin >> x;
  
  int a=0;
  
  if(x%11>6)
    a+=2;
  else if(x%11>0)
    a++;
  cout << x/11*2+a << endl;
}
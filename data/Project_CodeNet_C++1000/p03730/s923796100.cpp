#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  
  if(c==0){
    cout << "YES" << endl;
    return 0;
  }
  
  if(a<b)swap(a,b);
  while(a%b!=0){
    a %= b;
    swap(a,b);
  }
  
  puts(c%b==0?"YES":"NO");
  return 0;
}

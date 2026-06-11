#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int count = 0;
  
  if(a == 1 && b == 1 && c == 1)cout << 0 << endl;
  else if(a == b && b == c && b == a)cout << -1 << endl;
  
  else {
    bool hantei = true;
    while(hantei == true){
      if((a + 2) % 2 != 0)hantei = false;
      if((b + 2) % 2 != 0)hantei = false;
      if((c + 2) % 2 != 0)hantei = false;
      
      if(hantei == false)continue;
      
      int ak = a;
      int bk = b;
      int ck = c;
      
      a = (bk + ck) / 2;
      b = (ck + ak) / 2;
      c = (ak + bk) / 2;
      
      count ++;
    }
    cout << count << endl;
  }
}
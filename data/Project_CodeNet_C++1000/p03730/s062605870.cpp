#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,c;
  cin >> a >> b >> c;
  
  int i = 1;
  int flag = 0;
  if( (a % b) != 0 ){
    while(i <= 100){
      if( ((a * i) % b) == c ){
        flag = 1;
        break;
      }
      i++;
    }//while
  }//if
  
  if(flag == 1){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
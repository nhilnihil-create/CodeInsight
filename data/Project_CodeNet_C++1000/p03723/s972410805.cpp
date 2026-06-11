#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int  main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  int na=0, nb=0, nc=0;
  int cnt = 0;
  bool flag = false;
  while(a%2==0 && b%2==0 && c%2==0){
    ++cnt;
    na += (b+c)/2;
    nb += (a+c)/2;
    nc += (a+b)/2;
    
    a = na;
    b = nb;
    c = nc;
    if(a==b && b==c){
      flag = true;
      break;
    }
  }
  if(flag) cout << -1 << endl;
  else cout << cnt << endl;
  return 0;
}
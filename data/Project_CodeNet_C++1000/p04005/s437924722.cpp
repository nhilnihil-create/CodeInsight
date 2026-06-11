#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long X,Y,Z,sw = 0;
  cin >> X >> Y >> Z;
  if(X > Y && X > Z){
    sw = 0;
  }else if(Y > X && Y > Z){
    sw = 1;
  }else{
sw = 2;
  }
  long long i,dist;
  switch(sw){
    case 0:
      i = X / 2;
      dist = abs((X - i - i) * Y * Z);
      cout << dist << endl;
      break;
          case 1:
      i = Y / 2;
      dist = abs((Y - i - i) * X * Z);
      cout << dist << endl;
      break;
        case 2:
      i = Z / 2;
      dist = abs((Z - i - i)* Y * X);
      cout << dist << endl;
      break;
  }
return 0;
}
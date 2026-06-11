#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string o, e;
  cin >> o >> e;
  int n = o.size() + e.size();
  int cnt = 1;
  int num1 = 0, num2=0;
  for(int i=0; i<n; ++i){
    if(cnt%2==1){
      cout << o[num1];
      num1++;
    }
    else{
      cout << e[num2];
      num2++;
    }
    cnt++;
  }

}
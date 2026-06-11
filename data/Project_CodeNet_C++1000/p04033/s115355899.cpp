#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int a, b;
  cin >> a >> b;
  if((b-a)%2==1){
    if(a<0 && b>0) cout << "Zero" << endl;
    else cout << "Positive" << endl;
    return 0;
  }
  if((b-a)%2==0){
    if(a>0 && b>0) cout << "Positive" << endl;
    else if(a<0 && b<0) cout << "Negative" << endl;
    else cout << "Zero" << endl;
    return 0;
  }
  return 0;
}
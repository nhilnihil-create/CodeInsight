#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string a, b;
  cin >> a >> b;
  int asize = a.size();
  int bsize = b.size();
  if(asize!=bsize){
    if(asize>bsize) cout << "GREATER" << endl;
    else cout << "LESS" << endl;
    return 0;
  }
  if(asize==bsize){
    if(a>b) cout << "GREATER" << endl;
    if(a==b) cout << "EQUAL" << endl;
    else if(a<b) cout << "LESS" << endl;
    return 0;
  }
  return 0;
}
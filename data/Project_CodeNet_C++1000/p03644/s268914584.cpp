#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  //1からｎまで２で割って試す２・４・８・１６・３２・６４
  if(n>=64)cout << 64 <<endl;
  else if(n>=32)cout << 32 << endl;
  else if(n>=16)cout << 16 << endl;
  else if(n>=8)cout << 8 << endl;
  else if(n>=4)cout << 4 << endl;
  else if(n>=2)cout << 2 << endl;
  else if(n==1)cout << 1 << endl;
  
  return 0;
  
}

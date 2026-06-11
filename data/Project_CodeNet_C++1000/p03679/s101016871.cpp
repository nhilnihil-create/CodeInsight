#include<bits/stdc++.h> 
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main(){
  ull x,a,b;
  cin >> x >> a >> b;
  if( b > a+x ){
    cout << "dangerous" << endl;
  }else if( b > a && b <= a+x ){
    cout << "safe" << endl;
  }else{
    cout << "delicious" << endl;
  }
    
  return 0;
}

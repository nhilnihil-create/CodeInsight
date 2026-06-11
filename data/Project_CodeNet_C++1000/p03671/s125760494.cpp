#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int n,m;
  n = min(a,b);
  if(a < b){
    m = min(b,c);
  }
  else{
    m = min(a,c);
  }
  cout << n+m << endl;
}
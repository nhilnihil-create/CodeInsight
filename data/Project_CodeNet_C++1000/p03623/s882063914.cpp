#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,a,b,c,d;
  cin >> x >> a >> b;
  if(x<a){
    c=a-x;
  }
  else{
    c=x-a;
  }
  if(x<b){
    d=b-x;
  }
  else{
    d=x-b;
  }
  if(c<d){
    cout << "A" << endl;
  }
  else{
    cout << "B" << endl;
  }
}

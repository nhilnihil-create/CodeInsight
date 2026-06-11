#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
  int x, a, b; cin >> x >> a >> b;
  int s=0, t=0;
  s= (a-x)*(a-x); t= (b-x)*(b-x);
  if(min (s,t)==s)  cout << "A" << endl;
  else cout << "B" << endl;
}
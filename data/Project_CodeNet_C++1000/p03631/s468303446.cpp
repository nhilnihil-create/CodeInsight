#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
const int inf = 1000000000;
using namespace std;
int main(){
  int x; cin >> x;
  cout << ( x/100 == (x%100)%10 ? "Yes":"No" ) << endl;
}
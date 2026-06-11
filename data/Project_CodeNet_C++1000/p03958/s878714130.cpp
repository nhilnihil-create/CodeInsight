#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int main(void){
  int k, t;
  cin >> k >> t;
  int maxa = 0, tota = 0;
  for(int i=0; i<t; ++i){
    int a;
    cin >> a;
    maxa = max(maxa, a);
    tota += a;
  }
  if(tota%2){
    maxa = max(0, maxa -(tota+1)/2);
    cout << maxa *2 << endl;
    return 0;
  }
  maxa = max(0, maxa -tota/2);
  if(maxa) maxa = maxa *2 -1;
  cout << maxa << endl;  
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N ,a=0,ans=1;
  cin >> N ;
  for (int i=N ; i>1 ; i= (i-i%2)/2 ){
    a++ ;
  }
  for (int i= 0 ; i< a ; i++){
    ans*=2;
  }
  cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;

int main(void){
  int n, k;
  cin >> n >> k;
  
  int wa = 0;
  for( int i = 0 ; i < n ; i++ ){
    int a;
    cin >> a;
    if( a <= k-a ){
      wa += a * 2;
    }
    else{
      wa += (k - a) * 2;
    }
  }
  cout << wa << endl;
}
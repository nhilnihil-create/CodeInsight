#include <bits/stdc++.h>
using namespace std;
int main() {
  
int n , l , r , k ;
cin >> n ;
  int g = 0 ;
  for ( int i = 0 ; i < n ; i++ ){ 
    cin >> l >> r ;
   k = r - l + 1 ;
   g = k + g ;
  }    
cout << g << endl;   
       
}

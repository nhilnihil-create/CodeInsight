#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n , A, B;
  cin >> n >> A >> B;
  string s ;
  cin >> s ;
  int dom = 0;
  int fore = 0; 
  for ( int i=0 ; i<n ; i++){
    if (s.at(i) == 'c'){
      cout << "No"<< endl;
      continue ;
    }else if ( s.at(i) == 'a'){
      if (dom+fore<A+B){
      cout <<  "Yes"  << endl;
      dom++ ;
      continue ;
      }else {
        cout << "No"  << endl;
        continue ;
      }
    }else if ( s.at(i) == 'b'){
      if (dom + fore < A+B && fore < B){
      cout << "Yes"  << endl;
        fore++ ;
        continue ;
      }else {
        cout << "No"  << endl;
      continue ;
      }
    }
  }
}
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N; string s; cin >> N >> s;
  int counter = 0, need_left = 0;
  for( int i = 0; i < N; i++ ){
    if( counter == 0 ){
      if( s[i] == ')' ) need_left++;
      else counter++;
    }
    else{
      if( s[i] == ')' ) counter--;
      else counter++;
    }
  }
  int x = count(s.begin(), s.end(), '(');
  int need_right = 2 * x + need_left - N;
  for( int i = 0; i < need_left; i++ ) cout << '(';
  cout << s;
  for( int i = 0; i < need_right; i++ ) cout << ')';
  cout << endl;
}
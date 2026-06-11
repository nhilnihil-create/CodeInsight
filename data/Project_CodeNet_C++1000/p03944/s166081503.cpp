#include <bits/stdc++.h>
using namespace std;

int main() {
  int W ,H , N;
  cin >> W >> H >> N;
  vector <tuple <int , int , int >> A(N);
  for ( int i=0 ; i<N ; i++){
    int a,b,c;
    cin >> a >> b >> c;
    A.at(i)=make_tuple(c,a,b);
  }
  int x_max=W ,x_min=0 , y_max=H , y_min=0;
  for ( int i=0 ; i< N ; i++){
    int c,b, a;
    tie(c,a,b) = A.at(i) ;
    if ( c == 1){
      x_min=max(x_min,a);
      continue ;
    }
    if ( c == 2){
      x_max=min(x_max,a);
      continue ;
    }
    if ( c == 3){
      y_min =max(y_min,b);
      continue ;
    }
    if ( c == 4){
      y_max =min(y_max,b);
    }
  }
  if (x_min<x_max && y_min < y_max){
    cout << (x_max-x_min)*(y_max-y_min) <<endl;
  }else cout << 0 << endl;
}
      
  
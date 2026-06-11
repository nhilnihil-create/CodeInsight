#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w , n;
  cin >> w >> h >> n;
  vector < tuple <double,double,double >> A(n);
  for (int i=0 ; i<n ; i++){
    double a,b,c;
    cin >> a >> b >> c;
    A.at(i) = make_tuple(a,b,c) ;
  }
  double ld_x =0, ld_y = 0 , ru_x = w , ru_y = h;
  for ( int i=0 ; i<n; i++){
    double a,b,c;
    tie(a,b,c) = A.at(i) ;
    if ( c==1){
      ld_x = max(ld_x , a) ;
    }else if ( c==2){
      ru_x = min(ru_x , a) ;
    }else if ( c==3){
      ld_y = max(ld_y , b) ;
    }else if ( c==4){
      ru_y = min(ru_y , b) ;
    }
  }
  double c = (ru_x - ld_x)*(ru_y - ld_y) ;
  cout << ((ru_x <= ld_x)||(ru_y <= ld_y) ? 0 : c) << endl;
}
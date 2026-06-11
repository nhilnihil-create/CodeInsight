#include <bits/stdc++.h>
using namespace std;

int N ,i ,res ;
int A [100000];

int main (){
  scanf( "%d", &N );
  for ( int i=0; i < N ; i ++) scanf( "%d", &A[i] );
  sort (A, A+N);
  
  while ( i < N ){
    int cc = A[i] , f = 0;
    while ( i < N && A [ i ]== cc ) f++ , i++;
    res += f %2;
  }
  
  printf ( "%d\n", res );
}

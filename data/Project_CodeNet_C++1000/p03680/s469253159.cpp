#include <bits/stdc++.h>
using namespace std;
 
int main(void) {
    int N;
cin >> N ;
  int A[N];
  for (int i=0 ; i<N ; i++){
    cin >> A[i];
  }
  int count=0;
  for (int c=1 ; c != 2  ;){
   c=A[c-1];
     count++;
   if (count == N){
     cout << -1 << endl;
     return 0;
   }
  }
  cout << count << endl ;
}
    

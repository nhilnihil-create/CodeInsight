#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  long long N,P,A;
  long long odd=0,even=0;
  long long all=0;
  cin >> N >> P;

  for(int i=0;i<N;i++){
    cin >> A;
    if(A%2==0)even+=1;
    else odd+=1;
  }
  
  all=pow(2,N);
  if(odd==0){
   if(P==0) cout << all;
   else cout << 0;
  }
  else cout << all/2;
  return 0;
}
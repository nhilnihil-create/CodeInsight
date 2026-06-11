#include <bits/stdc++.h>
using namespace std;

unsigned GetDigit(unsigned num){
    return log10(num)+1;
}
main(){
  long int n,root,div,keep,maxnumber;
  cin >> n;
  root = (int)sqrt(n);
  keep=11;
  for(int i=1;i<=root;i++){
    div=n/i;
    if(n%i==0){
            maxnumber = max(GetDigit(i),GetDigit(div));
            keep = min(keep,maxnumber);
    }
  }
  cout << keep;
}
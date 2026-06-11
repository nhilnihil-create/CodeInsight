#include <bits/stdc++.h>

using namespace std;

int main(void){
  
  int A,B;
  cin>>A>>B;
  cout<<( (!(A%3)||!(B%3)||!((A+B)%3) )? "Possible":"Impossible")<<endl;
  return 0;
}

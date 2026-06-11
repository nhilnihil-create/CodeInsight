#include <bits/stdc++.h>

using namespace std;

int main(void){
  
  int X,A,B;
  cin>>X>>A>>B;
  if(A+X<B)     cout<<"dangerous"<<endl;
  else if(A<B)  cout<<"safe"<<endl;
  else          cout<<"delicious"<<endl;
  return 0;
}

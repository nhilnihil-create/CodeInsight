#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin>>A>>B;
  if(A%3==B%3 && A%3!=0)
    cout<<"Impossible"<<endl;
  else
    cout<<"Possible"<<endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C;cin>>A>>B>>C;
  if(A%3!=0&&B%3!=0&&(A+B)%3!=0)cout<<"Impossible"<<endl; 
  else cout<<"Possible"<<endl;
}
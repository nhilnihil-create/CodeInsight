#include<bits/stdc++.h>
using namespace std;
int main(){
int A,B,C,D;
  cin>>A>>B>>C>>D;
  int x=max(A,C);
  int y=min(B,D);
  if(x<=y)
    cout<<y-x<<endl;
  else
    cout<<0<<endl;
   return 0;
}
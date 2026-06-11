#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B;cin>>A>>B;
  if(A<=0 && B>=0) cout<<"Zero"<<endl;
  else if((B-A)%2==0 && B<0) cout<<"Negative"<<endl;
  else cout<<"Positive"<<endl;
}

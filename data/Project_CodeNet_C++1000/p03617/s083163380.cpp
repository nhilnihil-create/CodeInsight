#include<bits/stdc++.h>
#include<cmath>
#include<string>
using namespace std;
int main(){
  long long Q,H,S,D,N,X;
  cin>>Q>>H>>S>>D>>N;
  S=min(min(min(4*Q,2*Q+H),2*H),S);
  
  if(2*S>D) X=(N/2)*D+(N%2)*S;
  else X=S*N;
  cout<<X<<endl;
}

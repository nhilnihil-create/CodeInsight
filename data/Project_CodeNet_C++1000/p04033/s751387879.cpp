#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  ll a,b;cin>>a>>b;
  if(a>0&&b>0)cout<<"Positive"<<endl;
  else if((a<0&&b<0)&&(abs(a-b)+1)%2==0)cout<<"Positive"<<endl;
  else if((a<0&&b<0)&&(abs(a-b)+1)%2==1)cout<<"Negative"<<endl;
  else cout<<"Zero"<<endl;
}
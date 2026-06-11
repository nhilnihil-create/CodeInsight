#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll N,c=1000000007,p=1;
  cin>>N;
  for(int i=0;i<N;i++){
    p*=i+1;
    while(p>=c)p%=c;
  }
  cout<<p<<endl;
}
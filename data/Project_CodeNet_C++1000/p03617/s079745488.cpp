//need to think of a base line for example cost of one litre for each of the different
//bottle dimensions. 
#include<bits/stdc++.h>
using namespace std;
int main(){

	int q,h,s,d;cin>>q>>h>>s>>d;
  long long n;cin>>n;
  int fourth,half,one,two;
  fourth = q;
  half = min(h,2*fourth);
  one = min(s,2*half);
  two = min(d,2*one);
  if(n%2==0)cout<<n/2*two;
  else cout<<n/2*two+one;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  long long Q,H,S,D;
  long long N;
  cin>>Q>>H>>S>>D>>N;
  long long ONE=min(4*Q,min(2*H,min(2*Q+H,S)));
  long long TWO=min(D,ONE*2);
  cout<<N/2*TWO+N%2*ONE<<endl;
}
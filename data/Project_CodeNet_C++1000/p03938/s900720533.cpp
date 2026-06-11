#include<bits/stdc++.h>
using namespace std;
static const int base=700000000;
int main(){
  int N;cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    int x;cin>>x;x--;
    A.at(x)=base+i;
  }vector<int>a(N);
  vector<int>b(N);
  for(int i=0;i<N;i++){
  a.at(i)=30000*i+1;
    b.at(i)=A.at(i)-a.at(i);
  }for(int i=0;i<N-1;i++)
    cout<<a.at(i)<<" ";cout<<a.at(N-1)<<endl;
  for(int i=0;i<N-1;i++)
    cout<<b.at(i)<<" ";cout<<b.at(N-1)<<endl;
  return 0;
}
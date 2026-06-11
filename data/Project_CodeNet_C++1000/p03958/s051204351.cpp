#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;cin>>N>>M;
  int count=0;
  for(int i=0;i<M;i++){int a;cin>>a;count=max(count,a);}
  cout<<max(0,count*2-N-1)<<endl;
}
#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
  int N;
  cin>>N;
  vector<int>a(N);
  for(int i=0;i<N;i++){
     cin>>a[i];
  }
  set <int> k;int count=0;
  for(int i=0;i<N;i++){
     if(a[i]<3200){k.insert(a[i]/400);}
     else{count++;}
  }
  int Max=k.size()+count;
  int Min=1;
  
  if(k.size()>0){Min=k.size();}
  
  cout<<Min<<" "<<Max<<endl;
return 0;}
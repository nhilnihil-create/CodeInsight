#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,over=0;
  cin>>N;
  vector<int> a(N),c(8);
  
  for(int i=0;i<N;i++){
    cin>>a[i];
    for(int j=0;j<8;j++) if(j*400<=a[i]&&a[i]<(j+1)*400) c[j]=1;
    if(3200<=a[i]) over++;
  }
  
  int cnt=0;
  for(int j=0;j<8;j++) cnt+=c[j];
  
  int min,Max;
  
  if(cnt==0) min=1;
  else min=cnt;
  
  Max=cnt+over;
  
  cout<<min<<" "<<Max;
}
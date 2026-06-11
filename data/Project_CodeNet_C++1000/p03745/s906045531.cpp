#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int>A(N);
  int ans=0;
  int count=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  for(int i=0;i<N;i++){
    if(i==0){
      ans++;
      continue;
    }
    if(count==0&&A[i]<A[i-1])count=1;
    else if(count==0&&A[i]>A[i-1])count=2;
    else if(count==2&&A[i]<A[i-1]){
      count=0;
      ans++;
    }
    else if(count==1&&A[i]>A[i-1]){
      count=0;
      ans++;
    }
  }
  cout << ans << endl;
}
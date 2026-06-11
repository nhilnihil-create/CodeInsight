#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  
  int next=1;
  
  int ans=0;
  
  
  for(int i=0;i<N&&next!=2;i++){
    next=A[next-1];
    ans++;
  }
  
  if(next!=2){
    ans=-1;
  }
  
  
  cout<<ans<<endl;
}
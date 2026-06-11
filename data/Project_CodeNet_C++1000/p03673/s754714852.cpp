#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  deque<int>b;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(i%2==0)b.push_back(a);
    else b.push_front(a);
  }
  if(n%2==1)reverse(b.begin(),b.end());
  for(int i=0;i<n;i++){
    if(i!=n-1)cout<<b[i]<<" ";
    else cout<<b[i]<<endl;
  }
  return 0;
}


  

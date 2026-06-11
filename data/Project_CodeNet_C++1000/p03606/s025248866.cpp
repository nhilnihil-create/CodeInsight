#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int S;
  
  cin>>N;
  
  for(int i=1;i<=N;i++){
    int l,r;
    cin>>l>>r;
    int a;
    a=r-l+1;
    S=S+a;
  }
  
  cout<<S<<endl;
}
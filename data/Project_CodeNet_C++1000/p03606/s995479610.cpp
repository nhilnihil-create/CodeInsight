#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int i=0,n,kazu=0;
  cin>>n;
  
  while(i<n){
    int a,b;
    cin>>a>>b;
    kazu+=b-a+1;
    i++;
  }
  cout<<kazu<<endl;
 
}
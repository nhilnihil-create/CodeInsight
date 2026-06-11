#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int count;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    count+=b-a+1;
  }
  cout<<count<<endl;
}
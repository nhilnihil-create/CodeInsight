#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k=0;
  cin >>n;
  for(int i=0;i<n;i++){
    int l,m;
    cin >>l>>m;
    k+=(m-l+1);
  }
  cout <<k<<endl;
}
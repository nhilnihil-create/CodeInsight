#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int64_t j=1;
  for(int i=1;i<=N;i++){
    j*=i;
    j%=1000000007;
  }
  cout<<j<<endl;
}
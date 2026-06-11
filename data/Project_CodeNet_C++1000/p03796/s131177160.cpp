#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;cin>>N;
  int A=1;
  for (int i=1; i<=N; i++){
    A=A*i;
    A=A%(1000000000+7);
  }
  cout<<A<<endl;
}

  
  
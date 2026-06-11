#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  map<long long,long long>mp;
  for(int X=0;X<N;X++){
    long long A;cin>>A;
    mp[A]++;
  }
  int M=0;
  for(auto p:mp){
    auto value=p.second;
    if(value%2==1){
      M++;
    }
  }
  cout<<M<<endl;
}

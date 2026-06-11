#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  set<int> A;
  for(int i=2;i<=N;i++)
    A.insert(i);
  for(int i=2;i*i<=N;i++){
    if(!A.count(i))
      continue;
    vector<int> B(0);
    for(int j:A){
      if(j<i)
        continue;
      if(i*j>N)
        break;
      B.push_back(i*j);
    }
    for(int j:B)
      A.erase(j);
  }
  int l=1;
  for(int i:A){
    int j=0;
    for(int k=N;k>0;k/=i)
      j+=k/i;
    l=l*(j+1)%1000000007;
  }
  cout<<l<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N,M;
  cin>>N>>M;
  
  vector<int> vec(M*2);
  vector<int> res(N);
  
  for(int i=0;i<M*2;i++)
    cin>>vec.at(i);
  
  for(int i=0;i<M*2;i++)
    res.at(vec.at(i)-1)++;
  

  for(int i=0;i<N;i++) 
    cout<<res.at(i)<<endl;
  
 
}

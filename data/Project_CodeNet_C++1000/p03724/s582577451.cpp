#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  vector <int> A(M,0);
  vector <int> B(M,0);
  map<int,int>mp;

  for (int i=0;i<N;i++){
    cin>>A[i]>>B[i];
    mp[A[i]]++;
    mp[B[i]]++; 
  }
  int flag=0;
  for(auto itr=mp.begin();itr != mp.end();itr++){
    if((itr->second)%2 != 0) flag=1;
  }
  if(flag){
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  return 0;
}

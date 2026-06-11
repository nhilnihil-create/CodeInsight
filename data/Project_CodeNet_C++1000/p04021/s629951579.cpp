#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;vector<pair<int,int>>A(N);
  for(int i=0;i<N;i++){int t;cin>>t;A[i]=pair<int,int>(t,i%2);}
  sort(A.begin(),A.end());
  int ans=0;
  for(int i=0;i<N;i++){
    if(i%2!=A[i].second)ans++;
  }cout<<ans/2;
}
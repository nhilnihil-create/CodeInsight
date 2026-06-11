#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> ans1,ans2;
void a(int n,int k){
  if(n==1)return;
  if(n%2){
    a(n-1,k+1);
    ans1.push_back(k);
  }else{
    a(n/2,k+1);
    ans2.push_back(k);
  }
}
signed main(){
  int N;
  cin>>N;
  a(N+1,1);
  reverse(ans1.begin(),ans1.end());
  for(int i:ans2)ans1.push_back(i);
  int M=ans1.size();
  cout<<M*2<<endl;
  for(int i=0;i<M;i++)cout<<ans1[i]<<' ';
  for(int i=M;i>=1;i--)cout<<i<<(i==1?'\n':' ');
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  string S; cin>>S;
  int N=S.size();
  long long ans=(S.size()*(S.size()-1))/2;
  vector<long long>al(26);
  for(int i=0;i<N;i++)al[S[i]-97]++;
  for(int i=0;i<26;i++)ans-=al[i]*(al[i]-1)/2;
  cout<<ans+1<<endl;
}
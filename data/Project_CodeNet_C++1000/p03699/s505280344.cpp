#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N,ans=0;cin>>N;
  int s[N];vector<int> noten;
  for(int i=0;i<N;i++){cin>>s[i];ans+=s[i];if(s[i]%10!=0)noten.push_back(s[i]);}
  sort(noten.begin(),noten.end());
  int i=0;
  while(ans%10==0&&i<noten.size()){ans-=noten[i];i++;}
  if(ans%10!=0)cout<<ans<<endl;
  else cout<<"0"<<endl;
}
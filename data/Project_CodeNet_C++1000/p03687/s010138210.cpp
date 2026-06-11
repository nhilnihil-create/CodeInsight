#include<bits/stdc++.h>
using namespace std;
#define itn int
#define int int64_t
#define fi first
#define se second
signed main(){
  string s,c,e;
  int ans=0,m=0,sum;
  map<char,int> d;
  vector<char> v;
  cin>>s;
  for(int i=0;i<s.size();i++){
    d[s[i]]++;
    if(d[s[i]]==1) v.push_back(s[i]);
  }
  e=s;
  for(int j=0;j<v.size();j++){
    sum=0;
    s=e;
    while(true){
      string q;
      m=0;
      for(int i=0;i<s.size();i++){
	if(s[i]==v[j]) m++;
      }
      if(m==s.size()) break;
      for(int i=0;i<s.size()-1;i++){
	if(s[i]==v[j]||s[i+1]==v[j]){
	  q+=v[j];
	}
	else{
	  q+=s[i];
	}
      }
      swap(s,q);
      sum++;
    }
    if(j==0) ans=sum;
    ans=min(ans,sum);
  }
  cout<<ans<<"\n";
}

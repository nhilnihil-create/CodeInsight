#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char **argv)
{
	string s;
  cin>>s;
  map <char,int> mp;
  for(ll i=0;i<s.size();i++){
    mp[s[i]]++;
  }
  ll flag=1;
  for(auto itr=mp.begin();itr!=mp.end();++itr){
    if (itr->second%2!=0){
      flag=0;
      break;
    }
  }
  
  if (flag) cout<<"Yes"<<"\n";
  else cout<<"No"<<"\n";
	return 0;
}

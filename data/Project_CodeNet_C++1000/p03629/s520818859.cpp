#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7;
const ll LINF=1e18;
using namespace std;
#define int long long
//template
//main
signed main(){
  string A;cin>>A;
  std::vector<int> anki;
  set<char> s;
  for(int i=A.size()-1;i>=0;i--){
    s.insert(A[i]);
    if(s.size()==26){
      anki.push_back(i);
      s.clear();
    }
  }
  reverse(anki.begin(),anki.end());
  string ans;char ch;
  //if(anki.size()&&anki[0]==0)ans="a";
  int i=-1;
  for(int p:anki){
    //cout<<p<<endl;
    s.clear();
    for(i++;i<p;i++)s.insert(A[i]);
    for(ch='a';ch<='z';ch++){
      if(s.count(ch)==0){
        ans.push_back(ch);
        break;
      }
    }
    while(A[i]!=ch)i++;
  }
  s.clear();
  for(i++;i<A.size();i++)s.insert(A[i]);
  for(ch='a';ch<='z';ch++){
    if(s.count(ch)==0){
      ans.push_back(ch);
      break;
    }
  }
  cout<<ans<<endl;
}

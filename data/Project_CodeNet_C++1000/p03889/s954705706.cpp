#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  string s;
  cin>>s;
  string t(s);
  reverse(t.begin(),t.end());
  for(char &c:t){
    if(c=='b') c='d';
    else if(c=='d') c='b';
    else if(c=='p') c='q';
    else if(c=='q') c='p';
  }
  cout<<(s==t?"Yes":"No")<<endl;
  return 0;
}

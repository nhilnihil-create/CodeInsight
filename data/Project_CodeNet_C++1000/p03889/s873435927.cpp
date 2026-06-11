#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  string s;
  cin>>s;
  string t=s;
  reverse(t.begin(),t.end());
  rep(i,t.size()){
    if(s[i]=='b')s[i]='d';
    else if(s[i]=='d')s[i]='b';
    else if(s[i]=='p')s[i]='q';
    else if(s[i]=='q')s[i]='p';
  }
  cout<<(s==t?"Yes":"No")<<endl;
}
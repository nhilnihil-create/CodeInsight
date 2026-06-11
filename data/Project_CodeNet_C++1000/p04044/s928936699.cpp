#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n,l;
  cin>>n>>l;
  vector<string>s(n);
  rep(i,n)cin>>s[i];
  sort(s.begin(),s.end());
  string min;
  rep(i,n)
    min+=s[i];
    cout<<min<<endl;
  return 0;
}
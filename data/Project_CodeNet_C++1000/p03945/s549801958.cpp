#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
string s;
cin>>s;
int ans=0;
rep(i,s.size()-1){
  if(s[i]!=s[i+1]){
ans++;
  }
}

cout<<ans<<endl;
  return 0;
}

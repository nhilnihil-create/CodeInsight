#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;

  int max=0,ans=0;
  rep(i,n){
    if(s[i]=='I')ans++;
    else ans--;
    if(max<ans)max=ans;
  }
  cout << max << endl;
}

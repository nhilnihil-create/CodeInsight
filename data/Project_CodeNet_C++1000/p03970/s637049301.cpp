#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1<<30;

int main(){
  string s;cin>>s;
  string c="CODEFESTIVAL2016";
  int ans=0;
  for(int i=0;i<16;i++){
  	if(s[i]!=c[i])ans++;
  }
  cout<<ans<<endl;
}
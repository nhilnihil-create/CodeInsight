#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,c;
  /*cin>>a>>b>>c;
  if(a>b) cout<<"NO"<<'\n';
  else if(a+b>=c) cout<<"YES"<<'\n';
  else cout<<"NO"<<'\n';*/
  string s,na="YAKI";
  cin>>s;
  if(s.size()<4) cout<<"No"<<'\n';
  else{
    for(int i=0;i<4;i++){
      if(s[i]!=na[i]){
	cout<<"No"<<'\n';
	return 0;
      }
    }
    cout<<"Yes"<<'\n';
  }
  return 0;
}

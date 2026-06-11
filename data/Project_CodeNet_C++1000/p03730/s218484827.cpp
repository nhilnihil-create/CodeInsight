#include<bits/stdc++.h>
using namespace std;
int main(){
	int e,b,c;cin>>e>>b>>c;
  vector<int >nos(b,0);
  int seen=0;
  int i=2;
  int a = e;
  while(nos[a%b]!=1){
  	nos[a%b]=1;
    if(a%b==c){cout<<"YES";seen=1;break;}
    a=e*i;
    i++;
  }
  if(seen==0)cout<<"NO";
}
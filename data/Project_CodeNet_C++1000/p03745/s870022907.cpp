#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  vector<int >nos(n,0);
  for(int i=0;i<n;i++)cin>>nos[i];
  if(n==1){cout<<1;return 0;}
  int tot=1;
  int dec=0;
  if(nos[0]>nos[1])dec=-1;
  if(nos[1]>nos[0])dec=1;
  for(int i=2;i<n;i++){
      //cout<<nos[i-1]<<' '<<nos[i]<<' '<<dec<<'\n';
  	if(nos[i]>nos[i-1]){
    	if(dec==0){dec=1;continue;}
      if(dec==1)continue;
      if(dec==-1){//cout<<i<<'\n';
      tot++;dec=0;continue;}
    }
    if(nos[i]<nos[i-1]){
       // cout<<"here\n";
      if(dec==0){dec=-1;continue;}
      if(dec==-1)continue;
      if(dec==1){//cout<<i<<'\n';
      tot++;dec=0;continue;}
    }
    if(nos[i]==nos[i-1]){
    continue;
    }
  }
  cout<<tot;
}
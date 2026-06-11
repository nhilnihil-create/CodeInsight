#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  cin>>n;
  vector<int >nos(n,0);
  for(int i=0;i<n;i++)cin>>nos[i];
  sort(nos.begin(),nos.end());
  int sumi=0;
  for(int i=0;i<n;i++)sumi+=nos[i];
  if(sumi%10!=0)cout<<sumi;
  else{
  	for(int i=0;i<n;i++){
    	if((sumi-nos[i])%10!=0){cout<<sumi-nos[i];return 0;}
    }
    cout<<0;
  }
}
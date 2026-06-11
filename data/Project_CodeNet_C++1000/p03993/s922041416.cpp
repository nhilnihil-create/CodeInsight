#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  vector<int >nos(n,0);
  for(int i=0,a;i<n;i++){cin>>a;nos[i]=a-1;}
  int tot=0;
  for(int i=0;i<n;i++){
  	if(nos[nos[i]]==i)tot++;
  }
  cout<<tot/2;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  string s;
  cin>>n;
  cin>>s;
  int maxi=0;
  int x=0;
  for(int i=0;i<n;i++){
  	if(s[i]=='I')x+=1;
    else x-=1;
    //cout<<x<<' ';
    maxi = max(maxi,x);
  	}
  cout<<maxi;
}
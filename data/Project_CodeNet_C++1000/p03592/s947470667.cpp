#include<bits/stdc++.h>
using namespace std;
int main(){
	int H,W,K;cin>>H>>W>>K;
  	int pos=0;
  int count;
  for(int i=0;i<=H;i++)
    for(int j=0;j<=W;j++){
      	count = i*(W-j)+j*(H-i);
      	//cout<<i<<' '<<j<<' '<<count<<'\n';
      if(count==K)pos=1;
    }
  if(pos==0)cout<<"No";
  else cout<<"Yes";
}
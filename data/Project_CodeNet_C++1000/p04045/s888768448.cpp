/*

*/
#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,a,n) for(int i=(a);i<(n);i++)

int main(){
	short n,k;
	vector<short>d;
	
	cin>>n>>k;
	d=vector<short>(k);
	rep(i,k)cin>>d[i];
	
  //許可
	vector<bool>allow(10,true);
	rep(i,k)allow[d[i]]=false;
	
	int ans,hoge;
	for(ans=n;;ans++){
	  for(hoge=ans;hoge>0&&allow[hoge%10];hoge/=10);
    //cout<<hoge<<" "<<ans<<endl;
	  if(hoge==0)break;
	}
	cout<<ans<<endl;
}

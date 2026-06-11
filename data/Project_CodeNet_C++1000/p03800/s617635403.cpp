#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	char c[n+1];
	int ans[n+2];
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]=='o'){
			c[i]='0';
		}
		else{
			c[i]='1';
		}
		ans[i]=-1;
	}
	c[n]=c[0];
	for(int i=0;i<5;i++){
		if(i==0){
			ans[0]=0;
			ans[1]=0;
		}
		else if(i==1){
			ans[0]=0;
			ans[1]=1;
		}
		else if(i==2){
			ans[0]=1;
			ans[1]=0;
		}
		else if(i==3){
			ans[0]=1;
			ans[1]=1;
		}
		else{
			cout<<"-1";
			return 0;
		}
		for(int j=2;j<n+2;j++){
			ans[j]=ans[j-2]^ans[j-1]^(c[j-1]-'0');
		}
		if(ans[0]==ans[n]&&ans[1]==ans[n+1]){
			for(int i=0;i<n;i++){
				if(ans[i]==0){
					cout<<"S";
				}
				else{
					cout<<"W";
				}
			}
			return 0;
		}
	}
} 
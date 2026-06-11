#include <bits/stdc++.h>
using namespace std;

string s[200];
int n, m;

int main(){
	cin>>n>>m;
	
	for(int i=1; i<=n; i++){
		cin>>s[i];
		s[i]="#"+s[i]+"#";
	}
	
	for(int i=0; i<=n+1; i++){
		if(i==0||i==n+1){
			for(int j=0; j<=m+1; j++) cout<<"#";
			cout<<endl;
		}
		else cout<<s[i]<<endl;
	}
}

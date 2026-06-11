#include<bits/stdc++.h>
using namespace std;
int main(){
	int k,s;
	cin>>k>>s;
	int n=0;
	int m=min(k,s);
	for(int i=0;i<=m;i++) for(int j=0;j<=m;j++){
		if(s-i-j<=k&&i+j<=s){
			n++;
		}
	}
	cout<<n<<'\n';
}
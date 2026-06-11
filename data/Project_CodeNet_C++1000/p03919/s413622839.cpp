#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			string s;
			cin>>s;
			if(s=="snuke"){
				cout<<(char)('A'+j-1)<<i;
				return 0;
			} 
		}
	}
}

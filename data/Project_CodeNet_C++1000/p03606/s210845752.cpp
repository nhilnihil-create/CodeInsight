#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int p=0;
	cin>>n;
	while(n--){
		int u,v;
		cin>>u>>v;
		p+=v-u+1;
	}
	cout<<p;
	
	return 0;
}
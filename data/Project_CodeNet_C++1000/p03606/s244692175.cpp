#include<bits/stdc++.h>
using namespace std;
int main(){
	int l,r,rt=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>l>>r;
		rt+=abs(l-r)+1;
	}cout<<rt<<endl; 
}
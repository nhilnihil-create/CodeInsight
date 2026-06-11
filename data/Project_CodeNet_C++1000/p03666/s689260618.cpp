#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,A,B,C,D;
	cin>>n>>A>>B>>C>>D;
	for(int i=0;i<=n-1;i++)
		if(1LL*C*(n-1-i)-1LL*D*i<=B-A&&B-A<=1LL*D*(n-1-i)-1LL*C*i){
			cout<<"YES"<<endl;
			return 0;
		}
	cout<<"NO"<<endl;
}

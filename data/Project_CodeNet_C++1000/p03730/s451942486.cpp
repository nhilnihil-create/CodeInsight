#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,sum;
	cin>>a>>b>>c;
	for(int i=1;i<=1e6;i++){
		sum+=a*i;
		if((b*i+c)%a==0){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
} 
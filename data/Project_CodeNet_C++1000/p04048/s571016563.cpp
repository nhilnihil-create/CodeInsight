#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n,x;
	cin>>n>>x;
	long long int ans=n;
	long long int y=n-x;
	while(x!=0&&y!=0){
		if(x>y)
			swap(x,y);
		ans+=2*(y/x*x);
		y%=x;
	}
	cout<<ans-x-y<<endl;
}

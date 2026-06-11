#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
int n,x,y,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		ans+=y-x+1;
	}
	cout<<ans<<endl;
 	return 0;
}
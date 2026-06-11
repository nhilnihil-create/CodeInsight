#include<bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define mod 1000000007
#define P pair<int,int>
using namespace std;
signed main(){
	int n,i=1,x=1;
	cin>>n;
	while(n>x){
		i++;
		x+=i;
	}
	cout<<i<<endl;
}

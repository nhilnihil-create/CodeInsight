//by xiqiao
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int p[55],m;
int x[10005],head=201,tail=200,num;
void get(ll n){
	if(n==0)return;
	if(n&1){
		get(n/2);
		x[++tail]=++num;
	}
	else{
		get(n-1);
		x[--head]=++num;
	}
}
int main(){
	cin>>n;
	get(n);
	printf("%d\n",num*2);
	for(int i=head;i<=tail;i++)cout<<x[i]<<" ";
	for(int i=1;i<=num;i++)cout<<i<<" ";
	cout<<endl;
	return 0;
}
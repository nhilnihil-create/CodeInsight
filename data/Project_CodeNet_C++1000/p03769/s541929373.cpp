#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n;
	cin>>n;n++;
	int *a=new int[400],now=0;
	a+=200;
	for(int i=40;~i;i--){
		if(now){
			*(a+now-1)=now;
			now++;
		}
		if(n>>i&1){
			if(!now){
				now=1;continue;
			}
			a--;
			*a=now++;
		}
	}
	cout<<2*now-2<<'\n';
	for(int i=0;i<now-1;i++)
		cout<<*(a+i)<<' ';
	for(int i=1;i<now;i++)
		cout<<i<<' ';
	cout<<'\n';
	return 0;
}

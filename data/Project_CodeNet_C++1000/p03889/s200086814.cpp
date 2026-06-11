#include<cstdio>
#include<iostream>
#include<cstring>
#define maxn 100005
using namespace std;
char a[maxn],b[maxn];
char f[maxn];
int main(){
	f['b']='d';f['d']='b';
	f['p']='q';f['q']='p';
	cin>>a;int la=strlen(a);
	for(int i=la-1;i>=0;i--){
		b[i]=f[a[la-i-1]];
	}
	int tip=0;
	for(int i=0;i<=la-1;i++){
		if(b[i]!=a[i]){
			tip=1;break;
		}
	}
	if(tip==0) cout<<"Yes";
	else cout<<"No";
	return 0;
}
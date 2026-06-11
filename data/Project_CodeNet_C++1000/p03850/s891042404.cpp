#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;

int gi() {
	int x=0,o=1;char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') o=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*o;
}

int n;

int main() {
	cin>>n;ll f0=0,f1=-1e18,f2=-1e18;
	for(int i=1;i<=n;i++) {
		int x=gi();f0+=x;f1-=x;f2+=x;
		if(x<0) f2=max(f2,f1),f1=max(f1,f0);
		f1=max(f1,f2);f0=max(f0,f1);
	}
	cout<<f0;
	return 0;
}

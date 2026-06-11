#include<bits/stdc++.h>
using namespace std;
#define N 1111116

int n;
vector<long long> a,b;
long long cnt,ans;
char opt='+';

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();a.push_back(0);b.push_back(0);
	for (int i=1;i<=n;i++){
		if (i!=1) scanf(" %c",&opt);
		int x=read();cnt+=x;
		if (opt=='+') b.back()+=x;
		else a.push_back(x),b.push_back(0);
	}
	for (int i=1;i<(int) a.size();i++){
		ans=max(ans,cnt-2*(a[i]+b[i]));
		cnt-=2*a[i];
	}
	printf("%lld\n",max(ans,cnt));
	return 0;
}
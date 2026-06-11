#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
LL n;
int a[N],tot;
int main(){
	n=read()+1;
	tot=100;
	for (int i=1;i<=tot;i++)
		a[i]=i;
	int t=0;
	while (n>>(t+1))
		t++;
	for (int i=1;i<=t;i++)
		a[++tot]=i;
	int k=t;
	for (int x=t-1;x>=0;x--)
		if (n>>x&1){
			tot++;
			for (int i=tot;i>101+x;i--)
				a[i]=a[i-1];
			a[101+x]=++k;
		}
	cout << tot << endl;
	for (int i=1;i<=tot;i++)
		cout << a[i] << " ";
	return 0;
}
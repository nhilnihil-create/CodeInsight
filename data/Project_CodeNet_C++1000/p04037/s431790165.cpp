#include <bits/stdc++.h>
using namespace std;

template <typename _Tp> inline _Tp read(_Tp&x){
	char c11=getchar();x=0;while(!isdigit(c11))c11=getchar();
	while(isdigit(c11))x=x*10+c11-'0',c11=getchar();return x;
}

int a[101000],n;

int main(){
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	sort(a+1,a+n+1,greater<int>());
	int i,j;
	for(i=1;i<=n&&i+1<=a[i+1];++i);
	j=i+1;
	while(a[j]==i)++j;
	int d=(j-i+1&1)|(a[i]-i&1);
	puts(d?"First":"Second");
	return 0;
}
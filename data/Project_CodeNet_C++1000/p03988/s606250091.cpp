#include<bits/stdc++.h>
const int MN=200000+5,P=20101009;
using namespace std;
typedef long long ll;
template<typename T>inline T&IN(T&in){
	in=0;char c=getchar();int f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))in=in*10+c-'0',c=getchar();
	return in*=f;
}
int n,m,ans;
int a[MN],bin[MN];
void input(){
	IN(n);int mn=INT_MAX,mx=INT_MIN;
	for(int i=1;i<=n;++i)IN(a[i]),bin[a[i]]++,mn=min(mn,a[i]),mx=max(mx,a[i]);
	int f;
	if(mn*2==mx)f=1;
	else if(mn*2-1==mx)f=0;
	else return puts("Impossible"),void();
	if(f==1&&bin[mn]>1)return puts("Impossible"),void();
	if(f==0&&bin[mn]!=2)return puts("Impossible"),void();
	for(int i=mn+f;i<=mx;++i)if(bin[i]<2)return puts("Impossible"),void();
	puts("Possible");
}
int main(){
	input();
	return 0;
}
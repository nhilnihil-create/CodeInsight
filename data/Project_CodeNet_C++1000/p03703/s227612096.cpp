#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,a[200004],K,r[200004],CNT,dat[200004];
ll d[200004],ans;
struct BIT{
	void add(int id){
		for (;id<=CNT;id+=(id&-id)) dat[id]++;
	}
	int ANS(int id){
		int ret=0;for (;id;id-=(id&-id)) ret+=dat[id];return ret; 
	}
}T;
map<ll,int>mp;
int main(){
	read(n),read(K);
	mp[0]=1;
	for (int i=1;i<=n;i++) read(a[i]),a[i]-=K,d[i]=d[i-1]+a[i],mp[d[i]]=1;
	for (map<ll,int>::iterator it=mp.begin();it!=mp.end();it++) it->second=++CNT;
	for (int i=1;i<=n;i++) r[i]=mp[d[i]];
	T.add(mp[0]); 
	for (int i=1;i<=n;i++){
		ans+=T.ANS(r[i]);
		T.add(r[i]);
	}
	write(ans);
}
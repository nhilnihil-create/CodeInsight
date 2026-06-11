#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,lst,x,m_=1;
ll lzy[263144];
int cnt[263144];
void upd(int l,int r,int id,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		lzy[id]+=x;return;
	}
	upd(l,(l+r)/2,id*2+1,a,b,x),upd((l+r)/2+1,r,id*2+2,a,b,x);
}
void add(int l,int r,int id,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		lzy[id]+=x;cnt[id]++;return;
	}
	add(l,(l+r)/2,id*2+1,a,b,x),add((l+r)/2+1,r,id*2+2,a,b,x);
}
ll minans(int l,int r,int id,ll a,int num){
	if(l>m)return 1e18;
	if(l==r){
		num+=cnt[id];
		return a+lzy[id]-1ll*num*l;
	}
	return min(minans(l,(l+r)/2,id*2+1,a+lzy[id],num+cnt[id]),minans((l+r)/2+1,r,id*2+2,a+lzy[id],num+cnt[id]));
}
int main(){
	read(n),read(m),read(lst);
	while(m_<m)m_<<=1;
	for(int i=1;i<n;i++){
		read(x);
		if(lst<x){
			upd(1,m_,0,1,lst,x-lst);
			add(1,m_,0,lst+1,x,x+1);
			if(x<m)upd(1,m_,0,x+1,m,x-lst);
		}else{
			add(1,m_,0,1,x,x+1);
			upd(1,m_,0,x+1,lst,x+m-lst);
			if(lst<m)add(1,m_,0,lst+1,m,x+m+1);
		}
		lst=x;
	}
	write(minans(1,m_,0,0,0));
}
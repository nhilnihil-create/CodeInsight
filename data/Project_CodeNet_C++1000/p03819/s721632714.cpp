#include<bits/stdc++.h> 
using namespace std;
int q,w,e,r,t,c[100010];
struct qqq{
	int l,r;
}a[300010];
int read(){
	int sum=0;
	char st=getchar();
	while(st<'0'||'9'<st)st=getchar();
	while('0'<=st&&st<='9'){
		sum=(sum<<3)+(sum<<1)+st-'0';
		st=getchar();
	}
	return sum;
}
void add(int x,int y){
	while(x<=w){
		c[x]+=y;
		x+=x&(-x);
	}
}
int get(int x){
	int sum=0;
	while(x>0){
		sum+=c[x];
		x-=x&(-x);
	}
	return sum;
}
bool paix(qqq s1,qqq s2){
	return s1.r-s1.l<s2.r-s2.l;
}
int main(){
	cin>>q>>w;
	for(int i=1;i<=q;i++){
		a[i].l=read(),a[i].r=read();
	}
	sort(a+1,a+1+q,paix);
	int ans,st=0;
	for(int i=1;i<=w;i++){
		ans=0;
		for(;st<q&&a[st+1].r-a[st+1].l+1<i;st++){
			add(a[st+1].l,1),add(a[st+1].r+1,-1);
		}
		for(int j=i;j<=w;j+=i){
			ans+=get(j);
		}
		printf("%d\n",ans+q-st);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],b[N];
void read(int &x){
	int f=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
bool chk(int x){
	int i,p=1;
	for(int i=n;i<2*n-1;i++)
		if((a[i]>=x)==(a[i+1]>=x)){p=i;break;}
	for(int i=n;i>1;i--)
		if((a[i]>=x)==(a[i-1]>=x)){
			if(p==1||n-i<p-n)return a[i]>=x;
			break;
		}
	return a[p]>=x;
}
int main(){
	read(n);
	for(int i=1;i<=2*n-1;i++)
		read(a[i]),b[i]=a[i];
	sort(b+1,b+2*n);
	int l=1,r=2*n-1;
	while(l<r){
		int mid=l+r+1>>1;
		if(chk(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
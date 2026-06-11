#include<bits/stdc++.h>
using namespace std;
const int N=1e5+88;
int n,m,a[N];
int x,y;
inline int read(){
	char c=getchar();int s=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';c=getchar();
	}return s;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=m;i++){
		a[i]=read();
		if(a[i]%2==1){
			if(!x)x=i;
			else if(!y)y=i;
			else{
				puts("Impossible");
				return 0;
			}
		}
	}
	if(!x){
		for(int i=1;i<=m;i++)cout<<a[i]<<" ";
		cout<<endl;
		cout<<m+1<<endl;
		cout<<1<<" ";
		for(int i=1;i<m;i++){
			cout<<a[i]<<" ";
		}
		cout<<a[m]-1;
		return 0;
	}
	if(x&&!y){
		swap(a[x],a[m]);
		for(int i=1;i<=m;i++)cout<<a[i]<<" ";
		if(a[m]==1)cout<<endl<<m<<endl;
		else cout<<endl<<m+1<<endl;
		cout<<1<<" ";
		for(int i=1;i<m;i++){
			cout<<a[i]<<" ";
		}
		if(a[m]>1)cout<<a[m]-1;
		return 0;
	}
	if(x&&y){
		swap(a[x],a[1]);
		swap(a[y],a[m]);
		for(int i=1;i<=m;i++)cout<<a[i]<<" ";
		cout<<endl;
		if(a[m]>1)cout<<m;
		else cout<<m-1;
		cout<<endl;
		cout<<a[1]+1<<" ";
		for(int i=2;i<m;i++){
			cout<<a[i]<<" ";
		}
		if(a[m]>1)cout<<a[m]-1;
	}
}
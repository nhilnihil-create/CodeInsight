#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	int k=1,sum=0;
	char c=getchar();
	for(;c<'0' || c>'9';c=getchar()) if(c=='-') k=-1;
	for(;c>='0' && c<='9';c=getchar()) sum=sum*10+c-48;
	return sum*k;
}
int h,w,n;
ll ans[1000000],anss;
typedef pair<int,int> p;
map<p,int> a;
map<p,int>::iterator it;
int main(){
	h=read(),w=read(),n=read();
	for(re int i=1;i<=n;++i){
		int x=read(),y=read();
		for(re int s=max(1,x-2);s<=min(h-2,x);++s){
			for(re int t=max(1,y-2);t<=min(w-2,y);++t){
				++a[p(s,t)];
			}
		}
	}
	int s=0;
	for(it=a.begin();it!=a.end();++it){
		++ans[it->second];++s;
		//cout<<it->second<<" ";
	}
	anss=1ll*(h-2)*(w-2)-s;
	cout<<anss<<endl;
	for(re int i=1;i<=9;++i) cout<<ans[i]<<endl;
	return 0;
}
/*
6 3
2 3
1 2 
1 4 
4 5 
4 6 
0 2 5 1 2 3 
1 5 
1 3 
2 6 
*/
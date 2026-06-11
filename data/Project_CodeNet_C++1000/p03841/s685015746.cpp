#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
int n,a[251000],x[510];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(x[i]);
		if(a[x[i]]){puts("No");return 0;}
		a[x[i]]=i;
		for(int j=1;j<i;j++)
			q.push(make_pair(x[i],i));
	}
	for(int i=1;i<=n*n;i++){
		if(!q.empty()&&q.top().first<i){puts("No");return 0;}
		if(a[i]){
			for(int j=a[i]+1;j<=n;j++) q.push(make_pair(n*n+1,a[i]));
		}
		else{
			if(q.empty()){puts("No");return 0;}
			a[i]=q.top().second;q.pop();
		}
	}
	puts("Yes");
	for(int i=1;i<=n*n;i++)
		cout<<a[i]<<' ';cout<<'\n';
	return 0;
}

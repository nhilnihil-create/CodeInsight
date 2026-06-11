#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
long long a[200005],c[200005];
int b[200005];
long long n,k,num;
struct node{
	long long num;
	int id;
};
node ssum[200010];
bool cmp(node x,node y){
	if(x.num==y.num)return x.id<y.id;
	return x.num<y.num;
}
bool cmp2(node x,node y){
	return x.id<y.id;
}
long long sum(int x){
	long long ans=0;
	for(int i=x;i>=1;i-=(i&-i))ans+=c[i];
	return ans;
}
void add(int x,int y){
	for(int i=x;i<=n;i+=(i&-i))c[i]+=y;
}
int main(){
	while(cin>>n>>k){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]-=k;
			ssum[i].num=ssum[i-1].num+a[i];
			ssum[i].id=i;
		}
		sort(ssum+1,ssum+1+n,cmp);
		for(int i=1;i<=n;i++){
			b[ssum[i].id]=i;
		}
		sort(ssum+1,ssum+1+n,cmp2);
		num=0;
		for(int i=1;i<=n;i++){
			if(ssum[i].num>=0)
				num++;
			num+=sum(b[i]);
			add(b[i],1);
		} 
		cout<<num<<endl;
		
	}
	return 0;
}
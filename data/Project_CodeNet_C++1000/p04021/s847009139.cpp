#include<bits/stdc++.h>
using namespace std;
	
long long n;
long long ans=0;
struct node{
	int num,p;
}a[100005];

bool cmp(node x,node y){
	return x.num<y.num;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a[i].num;
	a[i].p = i;	
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if((abs(i-a[i].p))%2==1)ans++;
	}
	cout<<ans/2<<endl;
}
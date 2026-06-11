#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<cassert>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
using namespace std;
long long times[200005],num[200005];
long long a[100005];
long long b[200005];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	long long sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]--;
	}
	for(int i=1;i<n;i++){
		int x=a[i-1],y=a[i];
		if(y<x) y+=m;
		sum+=y-x;
		times[x+1]++;
		times[y+1]--;
		num[x+1]-=x;
		num[y+1]+=x;
	}
//	for(int i=0;i<2*m;i++) cout<<times[i]<<" ";
//	cout<<endl;
//	for(int i=0;i<2*m;i++) cout<<num[i]<<" "; 
//	cout<<endl;
//	cout<<times[0]<<" "<<num[0]<<endl;
	for(int i=1;i<2*m;i++){
		times[i]+=times[i-1];
		num[i]+=num[i-1];
		b[i]=i*times[i]+num[i]-times[i];
//		cout<<times[i]<<" "<<num[i]<<" "<<b[i]<<endl;
	}
	long long ma=-1;
	for(int i=0;i<m;i++){
		b[i]=b[i]+b[i+m];
//		cout<<b[i]<<"md"<<endl;
		ma=max(ma,b[i]);
	}
//	cout<<ma<<endl;
	cout<<sum-ma;
}
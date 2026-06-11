#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
using namespace std;

#define ll long long

#define debug_message 0
#define debug if (debug_message)

#define sz(x) (int)x.size()

int i,t,j;
int n,m,nt,a[100005],b[100005],cnt;
string s,s1,s2;
map<int,int> posa,posb;

int main(){
	scanf("%d",&n);
	
	for (i=1; i<=n; ++i){
		scanf("%d",&a[i]);
		b[i]=a[i];
		posa[a[i]]=i;
	}
	
	sort(b+1,b+n+1);
	
	for (i=1; i<=n; ++i){
		posb[b[i]]=i;
	}
	
	for (i=1; i<=n; ++i){
		if (abs(posa[a[i]]-posb[a[i]])%2==1){
			++cnt;
		}
	}
	
	printf("%d\n",cnt/2);
	
	return 0;
}
/*
3: odd difference
2: even difference
*/
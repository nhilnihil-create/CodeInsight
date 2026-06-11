#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
using namespace std;
const int maxn=1e5+9;
int a[maxn]={};
int main() {
    int n;
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	sort(a,a+n,greater<int>());
	int i=0;
	while(i<n-1&&a[i+1]>i+1) i++;
	int t1=a[i]-i-1,t2=0;
	while(i+t2<n-1&&a[i+t2+1]>i) t2++;
	if(t1&1||t2&1) puts("First");
	else puts("Second");
}
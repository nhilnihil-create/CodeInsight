#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=2e5+5;
int a[N],n,pos,len1,len2;
int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	rep(i,1,n) if(a[i]>=i&&a[i+1]<i+1){	pos=i; break; }
	rep(i,pos+1,n) if(a[i]>=pos) len1++;
	puts((len1&1)||((a[pos]-pos)&1)?"First":"Second");
	return 0;
}
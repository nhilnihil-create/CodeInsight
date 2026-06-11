#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define int long long
#define ll long long
template <typename T> void read(T &x) {
    x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9') x =(x<<1)+(x<<3)+c-'0',c=getchar();x *= f;
}
ll sum;
int n,a[N];
signed main() {
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),sum+=a[i];
	if(sum%(n*(n+1)/2)!=0)return puts("NO")*0;
	sum/=(n*(n+1)/2);
	for(int i=1;i<n;i++){
		int diff=a[i+1]-a[i],tmp=(sum-diff)/n;
		if(tmp<0||tmp*n!=(sum-diff)){
			return puts("NO")*0;
		}
	}
	return puts("YES")*0;
}

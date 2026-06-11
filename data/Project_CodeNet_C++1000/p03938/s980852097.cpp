#include<bits/stdc++.h>
using namespace std;
const int N=20005;
int b[N],n,x;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&x),b[x]+=i;
	for (int i=1;i<=n;i++)printf("%d ",(n+1)*i);
	puts("");
	for (int i=1;i<=n;i++)printf("%d ",(n+1)*(n-i+1)+b[i]);
}
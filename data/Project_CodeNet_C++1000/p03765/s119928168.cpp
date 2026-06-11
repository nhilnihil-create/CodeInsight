#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int s[N],t[N],Q,a,b,c,d;
char S[N],T[N];
int main(){
	scanf("%s%s",S,T);
	scanf("%d",&Q);
	for (int i=0;S[i];i++)s[i+1]=s[i]+(S[i]=='A'?1:2);
	for (int i=0;T[i];i++)t[i+1]=t[i]+(T[i]=='A'?1:2);
	while (Q--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if ((s[b]-s[a-1])%3==(t[d]-t[c-1])%3)puts("YES");
		else puts("NO");
	}
}

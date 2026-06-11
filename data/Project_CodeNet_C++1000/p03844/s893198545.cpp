#include<bits/stdc++.h>
#define YY "YES\n"
#define NN "NO\n"
#define f first
#define s second
#define LL long long
using namespace std;

LL n,m;
char c;
int main(){
	scanf("%d %c %d",&n,&c,&m);
	if (c=='+'){
		cout<<n+m<<"\n";
	}
	else cout<<n-m<<"\n";
	
}
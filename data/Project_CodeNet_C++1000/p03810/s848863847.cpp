#include<bits/stdc++.h>
 
using namespace std;
 
const int N=100005;
 
int n,a[N],las,t,g,s,f;
char str[2][10]={"First","Second"};
int gcd(int x,int y){return y?gcd(y,x%y):x;}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	while(true){
		s=t=0;
		for(int i=1;i<=n;i++){
			if(a[i]&1)t++,las=i;else s^=1;
		}
		if(s){puts(str[f]);break;}
		if(t>1||a[las]==1){puts(str[f^1]);break;}
		a[las]--;g=0;f^=1;
		for(int i=1;i<=n;i++)g=gcd(g,a[i]);
		for(int i=1;i<=n;i++)a[i]/=g;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,a[111111];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
bool chk(){
	int id = -1, even = 0, odd = 0;
	for(int i=1; i<=n; i++)
		if(a[i] % 2==0)
			even++;
		else{
			odd++;
			id = i;
		}
	if(even % 2 == 1)return true;
	if(odd > 1)return false;
	if(a[id] == 1)return false;
	a[id] --;
	int g=0;
	for(int i=1; i<=n; i++)
		g=gcd(g,a[i]);
	for(int i=1; i<=n; i++)
		a[i]/=g;
	return !chk();
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	puts(chk()?"First":"Second");
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s="RYBG";
int n,m,d;

int cal(int x,int y){
	if (d&1) return x%2<<1|y%2;
	return ((x+y)%(d*2)/d)*2 + ((x+d-(x+y)%d/2)%d < d/2);
}

int main(){
	cin>>n>>m>>d;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++)
			printf("%c",s[cal(i,j)]);
		puts("");
	}
}
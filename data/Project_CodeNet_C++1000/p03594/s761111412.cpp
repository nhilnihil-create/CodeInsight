#include<bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
#define itn int
#define gc getchar
#define cs const

int x,y;
int n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int re i=0;i<n;++i){
		for(int re j=0;j<m;++j){
			x=(m+i+j)/k%2;
			y=(m+i-j)/k%2;
			printf("%c","RGBY"[2*x+y]);
		}
		putchar('\n');
	}
	return 0;
}
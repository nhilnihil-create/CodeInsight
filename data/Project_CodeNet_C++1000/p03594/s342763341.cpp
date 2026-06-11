#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int h, w, d;
char c[5] = "RYGB";
int main(){
	scanf("%d%d%d", &h, &w, &d);
	rep(i,h){
		rep(j,w) printf("%c", c[(i+j)/d%2*2+(i-j+w)/d%2]);
		puts("");
	}
}
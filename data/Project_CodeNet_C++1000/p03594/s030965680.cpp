#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

string s[2]{
	"RY",
	"GB"
};
int main(){
	int h,w,d;cin>>h>>w>>d;
	rep(i,h){
		rep(j,w){
			int x=i-j,y=i+j;
			int a=(x+2*d*1000)%(2*d),b=(y+2*d*1000)%(2*d);
			printf("%c",s[a>=d][b>=d]);
		}
		puts("");
	}
}
#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,d;
const char s[]="RGBY";
int main(){
    cin>>n>>m>>d;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            putchar(s[(N+i+j)/d%2*2+(N+i-j)/d%2]);
		}
		puts("");
	}
}
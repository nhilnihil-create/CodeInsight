#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int x=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
int main(){
	puts(read()<1200?"ABC":"ARC");
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
template<class T>inline void init(T&x){
	x=0;char ch=getchar();bool t=0;
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') t=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch-48);
	if(t) x=-x;return;
}
const char symbol[4]={'R','G','B','Y'};
int n,m,k;
int main()
{
	init(n),init(m),init(k);
	for(int i=0;i<n;putchar('\n'),++i) {
		for(int j=0;j<m;++j) {
			int x=((m+i+j)/k)&1;
			int y=((m+i-j)/k)&1;
			putchar(symbol[(x<<1)+y]);
		}
	}
	return 0;
}

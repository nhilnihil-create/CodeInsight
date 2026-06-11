# include <iostream>
# include <cstdio>
# include <cmath>
# include <cstring>
# include <string>
# include <cstdlib>
# include <algorithm>
# include <stack>
# include <queue>
# include <vector>
# define maxx (103)
# define Pi (3.14159265358979)
# define inf (2147483647)
using namespace std;
int read() {
	int x=0,f=1;
	char ch;
	while(ch<'0'||ch>'9')  {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int main() {

	char c;
	int a=0,i;
	
	for(i = 1;i <= 2;i++){
		c=getchar();
		if(c=='9'){
			puts("Yes");
			return 0;
		}
	}
	puts("No");

	return 0;
}
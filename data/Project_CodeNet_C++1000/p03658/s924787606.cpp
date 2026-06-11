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
int a[55];
int n,k,ans;
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
bool cmp(int a,int b){
	return a>b;
}
int main() {

	n=read();
	k=read();
	
	int i;
	for(i = 1;i <= n;i++){
		a[i]=read();
	}
	
	sort(a+1,a+1+n,cmp);
	
	for(i = 1;i <= k;i++){
		ans+=a[i];
	}
	cout << ans << endl;

	return 0;
}
#include<bits/stdc++.h>
using namespace std;
string s="RGBY";
int n,i,j,x,y,d,m;
inline int read(){
	int x=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar(); 
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-48;
		c=getchar();
	}
	return x*f;
}
int main(){
	n=read();m=read();d=read();
	for(i=0;i<=n-1;i++){
	  for(j=0;j<=m-1;j++){
	 	 x=(m+i+j)/d%2;
	 	 y=(m+i-j)/d%2;
	 	 cout << s[2*x+y];
	 }
	 cout << endl;
    }
	return 0;
} 
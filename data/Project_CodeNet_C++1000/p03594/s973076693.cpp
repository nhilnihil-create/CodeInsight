#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    write(a); puts("");
}
char an[4];
int n,m,d;
int main(){
	an[0]='R'; an[1]='Y'; an[2]='G'; an[3]='B';//R, Y, G or B
    n=read(); m=read(); d=read();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int t1=((i+j)/d)&1,t2=((i+m-1-j)/d)&1;
			putchar(an[t1*2+t2]);
		}
		puts("");
	}
}
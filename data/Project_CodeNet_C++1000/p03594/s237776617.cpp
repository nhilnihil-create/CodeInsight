#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int n,m,d;
inline void work1() {
    for(int i=1;i<=n;i++) {
	for(int j=1;j<=m;j++) putchar((i+j)&1?'R':'B');
	puts("");
    }
}
inline char C(int x,int y) {
    x/=d,y/=d;
    if(x%2==0) return y%2?'R':'B';
    else return y%2?'G':'Y';
}
inline void work2() {
    for(int i=1;i<=n;i++) {
	for(int j=1;j<=m;j++) putchar(C((i+j+10000)/2,(i-j+10000)/2));
	puts("");
    }
}
int main() {
    cin>>n>>m>>d;
    if(d&1) work1();
    else d>>=1,work2();
    return 0;
}
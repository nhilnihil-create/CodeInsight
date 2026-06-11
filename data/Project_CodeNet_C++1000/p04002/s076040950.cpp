#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
long long ans[10];
map <int,map <int,int> > w;
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int main() {
    int H,W,n;
    cin>>H>>W>>n;
    ans[0]=1LL*(H-2)*(W-2);
    for(int i=1;i<=n;i++) {
	int x=gi(),y=gi();
	for(int a=x-1;a<x+2;a++)
	    for(int b=y-1;b<y+2;b++)
		if(a>1&&a<H&&b>1&&b<W) {
		    int &c=w[a][b];
		    --ans[c],++ans[++c];
		}
    }
    for(int i=0;i<10;i++) cout<<ans[i]<<endl;
    return 0;
}
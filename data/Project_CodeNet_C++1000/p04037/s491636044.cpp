#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100010
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,a[N]; 
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;++i){
		if(i+1>a[i+1]){
			int j=0;
			while(a[i+j+1]==i)++j;
			if(((a[i]-i)&1)||(j&1)){
				printf("First\n");
			}
			else{
				printf("Second\n");
			}
			break;
		}
	}
	return 0;
}

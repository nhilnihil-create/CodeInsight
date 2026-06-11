#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll read(){
	char ch=getchar();ll x=0,f=1;
	while(ch>'9' || ch<'0'){
        if(ch=='-') f=-1;
	    ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int a[2020202];

bool cmp(int a,int b){
	return a>b; 
} 


int main(){
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(i+1>a[i+1]){
			int ans=0;
			for(int j=i+1;a[j]==i;j++) ans^=1;
			ans|=(a[i]-i)&1;
			if(ans){
				puts("First");
			} 
			else{
				puts("Second");
			}
			return 0;
		}
	}
	return 0;
}


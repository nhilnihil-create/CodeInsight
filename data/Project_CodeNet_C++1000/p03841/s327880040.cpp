#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define G() Cr=getchar()
int Xr;char Cr;
inline int  rd(){
	Xr=0;G();
	while(Cr<'0'||Cr>'9')G();
	while(Cr>='0'&&Cr<='9')Xr=(Xr<<1)+(Xr<<3)+Cr-'0',G();
	return Xr;
}

int n;
int pos[250005];
struct node{
	int num,p;
}e[5005];

bool comp(node x,node y){
	return x.p<y.p;
}
int main(){
	n=rd();
	for(int i=1;i<=n;i++)
		e[i].num=i,e[i].p=rd(),pos[e[i].p]=i;
		
	sort(e+1,e+1+n,comp);	
		
	int l=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<e[i].num;j++){
			while(pos[l])l++;
			if(l>=e[i].p){
				puts("No");
				return 0;
			}
			pos[l++]=e[i].num;
		}	
	}
	
	int r=n*n;
	for(int i=n;i>=1;i--){
		for(int j=n;j>e[i].num;j--){
			while(pos[r])r--;
			if(r<=e[i].p){
				puts("No");
				return 0;
			}
			pos[r--]=e[i].num;
		}
	}
	
	puts("Yes");
	for(int i=1;i<=n*n;i++)printf("%d ",pos[i]);
	puts("");
}
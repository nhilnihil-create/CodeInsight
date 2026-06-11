#include<bits/stdc++.h>
int a,b;
using namespace std;
int main(){
	scanf("%d%d",&a,&b);
	if(a>b) swap(a,b);
	if(a<=0&&0<=b) return puts("Zero"),0;
	if(a>0) return puts("Positive"),0;
	int len=(b-a+1);
	if(len&1) puts("Negative");
	else puts("Positive");
}
#include<bits/stdc++.h>
using namespace std;
int i,j;char c;
int main(){
	scanf("%d %c %d",&i,&c,&j);
	if (c=='+') printf("%d\n",i+j);
	else printf("%d\n",i-j);
}
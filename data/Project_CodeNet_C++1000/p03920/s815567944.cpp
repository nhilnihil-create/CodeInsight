#include<bits/stdc++.h>
using namespace std;
int x,t;
int main()
{
	scanf("%d",&x);
	for (int i=1;i<=x;i++)
	 if (i*(i+1)/2>=x) {
	 	t=i; break;
	 }
	for (int i=t;i>=1;i--)
	 if (i*(i-1)/2<x) {
	 	printf("%d\n",i); x-=i;
	 } 
}
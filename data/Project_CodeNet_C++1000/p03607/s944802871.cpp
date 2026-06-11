#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;

int main()
{
 int N,a[100002]={-1,};
 scanf("%d",&N);
 for(int i=1;i<=N;i++)
 {
	scanf("%d",&a[i]);
 }
 sort(a,a+N+1,greater<>());
 int ans=0,nw=1;
 for(int i=0;i<N;i++)
 {
	if(a[i]==a[i+1]){nw++;}
	else{if(nw%2!=0){ans++;} nw=1;}
 }
 printf("%d\n",ans);
} 


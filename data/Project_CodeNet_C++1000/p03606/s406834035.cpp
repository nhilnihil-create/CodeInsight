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
 int N;
 scanf("%d",&N);
 int ans=0;
 for(int i=0;i<N;i++)
 {
	int a,b;
	scanf("%d %d",&a,&b);
	ans=ans+b-a+1;
 }
 printf("%d\n",ans);
} 


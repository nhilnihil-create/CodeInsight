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
typedef long long int ll;
const ll INF=pow(10,15);
ll N;
//35
int main()
{
ll a,b,x;
 scanf("%lld %lld %lld",&a,&b,&x);
 ll anx=a/x,bnx=b/x;
 if(a%x!=0){anx++;}
 ll ans=bnx-anx+1;
 printf("%lld\n",ans);
} 
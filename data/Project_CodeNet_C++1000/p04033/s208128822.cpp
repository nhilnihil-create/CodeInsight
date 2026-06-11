#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b;
int main(){
    scanf("%d%d",&a,&b);
	if (a>0) puts("Positive"); else
    if (a==0||(a<0&&b>0)) puts("Zero"); else
    if ((abs(b)-abs(a))%2!=0) puts("Positive");
	else puts("Negative");
	return 0;
}
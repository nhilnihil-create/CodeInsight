#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	long long x,y;
	scanf("%lld%lld",&x,&y);
	if(abs(x-y)<=1) puts("Brown");
	else puts("Alice");
}

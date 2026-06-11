#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<string>
//#include<string>
//#include<sstream>
using namespace std;

int main()
{
	long long a[100000],i;
	long long num=0;
	i=1;
	while(num<=1000000000){
		num+=i;
		a[i]=num;
		i++;
	}
	int sum=i;
	int x;
	scanf("%d",&x);
	for(i=1;i<=sum;i++){
		if(x<=a[i]){
			printf("%d\n",i);
			break;
		}
	}
}
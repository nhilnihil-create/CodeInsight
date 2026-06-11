#include<iostream>
#include<cstdio>
#include<algorithm>
int a[4];
using namespace std;
int main()
{
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1,a+1+3);
	if(a[1]==5&&a[2]==5&&a[3]==7) printf("YES\n");
	else printf("NO\n");
}
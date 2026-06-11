#include <bits/stdc++.h>
#define sort stable_sort
using namespace std; 

int _;

int a,b;

int main()
{
	scanf("%d%d",&a,&b);
	printf((a+b)%3 && a%3 && b%3 ?"Impossible\n":"Possible\n");
	return 0;
}


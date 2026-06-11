#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main()
{
	int a,b,c,d;
	scanf("%d %d %d %d", &a,&b,&c,&d);
	 
	if(max(a,c)<=min(b,d)) cout << min(b,d)-max(a,c);
	else cout << 0;
}
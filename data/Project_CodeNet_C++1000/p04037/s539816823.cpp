#include<bits/stdc++.h>
using namespace std;
int n, a[100005];
int main ()
{
	scanf ("%d", &n);
	for (int i=1; i<=n; i++)
		scanf ("%d", &a[i]);
	sort (a + 1, a + n + 1);
	reverse (a + 1, a + n + 1);
	int x = 0;
	a[0] = a[1];
	while (a[x + 2] > x + 1 && x + 1 < n) x ++;
	int right=0,up=0,k=x;
	while (x<a[k] && k<=n)
		right++,k++;
	up=a[x+1]-x;
	right--;
	if (up%2==1 && right%2==1)
		printf ("Second\n");
	else 
		printf ("First\n");
	return 0;
}

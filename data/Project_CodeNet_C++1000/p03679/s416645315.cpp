#include <bits/stdc++.h>
using namespace std;
int main()
{	
	int a,b,c;
	cin>>a>>b>>c;
	printf(c-b>a?"dangerous":b>=c?"delicious":"safe");
	return 0;
}
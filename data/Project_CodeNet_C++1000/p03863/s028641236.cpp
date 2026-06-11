#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
    cin>>a;
    if(a[0]==a[a.size()-1])
		if(a.size()%2==1) puts("Second");
		else puts("First");
	else
		if(a.size()%2==0) puts("Second");
		else puts("First");
}
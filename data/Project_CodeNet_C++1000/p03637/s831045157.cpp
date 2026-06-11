#include <bits/stdc++.h>
#define in(n)  int n; cin>>n;
#define loop for(int i=0;i<n;i++)
#define pb push_back
#define pf push_front
#define ll long long int
using namespace std;
int  main()
{
int n;
cin>>n;
ll ar[n];
loop
cin>>ar[i];
int m4=0;
int m2=0;
int m1=0;
loop{
if((ar[i]%4==0))
	m4+=2;
else if(ar[i]%2==0 )
	m4++;
}
if(((n/2)*2)<=m4)
	puts("Yes");
else
	puts("No");
}	

	

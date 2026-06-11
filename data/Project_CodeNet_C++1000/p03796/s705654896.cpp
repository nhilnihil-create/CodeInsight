#include <bits/stdc++.h>
using namespace std;
int main()
 
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	unsigned long long int n,power=1,i,mod=1e9+7;
     cin>> n;
     for(i=1;i<=n;i++)

     {
     	power=(power*i);
     	power=power%(mod);
     }
     cout<< power;
 }
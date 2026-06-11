#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int t[n];
	int suma=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>t[i];
		suma+=t[i];	
	}
	
	
	int b;
	cin>>b;
	int be[b];
	
	int aux1,aux2;
	
	
	for(int i=0;i<b;i++)
	{
		cin>>aux1>>aux2;	
		be[i]=suma-t[aux1-1]+aux2;	
	}
	
	for(int i=0;i<b;i++)
		cout<<be[i]<<endl;
	
	
	return 0;
}
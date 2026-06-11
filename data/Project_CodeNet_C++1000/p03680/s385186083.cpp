#include<bits/stdc++.h>
using namespace std;
int main()
{

int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
	cin>>arr[i];
set<int>found;
int i = 1;
int r=0;
while(i!=2)
{
	found.insert(i);
	i = arr[i-1];
	r++;
	if(found.find(i)!=found.end())
	{
		r=-1;
		break;
	}
}
cout<<r<<"\n";
}
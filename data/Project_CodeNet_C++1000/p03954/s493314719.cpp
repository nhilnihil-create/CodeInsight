#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
#define opr iterator
typedef long long ll;
using namespace std;
int n;
int per[200001];
bool ok[200001];
void get(int standard)
{
	for(int i=1;i<=2*n-1;i++)
	{
		ok[i]=(per[i]>=standard);
//		cout<<ok[i]<<"   ";
	}
	return;
}
bool check()
{
	int i,j;
	for(i=n,j=n;i>1&&j<2*n-1;i--,j++)
	{
		if(ok[i]==ok[i-1])
		{
		 	return ok[i];
		}
		else if(ok[j]==ok[j+1])
		{
			return ok[j];
		}
	}
	return ok[1];
}
int main()
{
	cin>>n;
	for(int i=1;i<=2*n-1;i++)
	{
		cin>>per[i];
	}
	int left=1;
	int right=2*n-1;
	int mid;
	while(left<right)
	{
		mid=(left+right+1)/2;
//		cout<<endl<<endl<<left<<"  LLL   RRR   "<<right<<endl<<endl;
//		cout<<"mid "<<mid<<endl; 
		get(mid);/*
		cout<<"mid= "<<mid<<endl;
		cout<<"left=  "<<left<<"      "<<"right=  "<<right<<endl;
		for(int i=1;i<=2*n-1;i++)
		{
			cout<<ok[i]<<" ";
		}
		cout<<endl;
		cout<<check()<<endl;*/
		if(check())
		{
			left=mid;
		}
		else
		{
			right=mid-1;
		}
//		system("pause");
	}
	cout<<right<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define bg begin()
#define end end()
#define sz size()
#define vi vector<int>
#define vl vector<long long int>
int main(){
	fast;
	string val;
	cin>>val;
	int f[26]={0};
	for(int i=0;i<val.length();i++)
		f[val[i]-97]++;
	for(int i=0;i<val.length();i++)
		if(f[i]>1)
		{
			cout<<"no";
			return 0;
		}
	cout<<"yes";
	return 0;
}


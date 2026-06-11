#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	int n,m,w1,w2,cnt=0;
	cin>>n>>m;
	string arr1[n],arr2[m];
	for(int i=0;i<n;i++)
		cin>>arr1[i];
	for(int i=0;i<m;i++)
		cin>>arr2[i];
	w1=arr1[0].length();
	w2=arr2[0].length();
	for(int j=0;j+m<=n;j++)				//row
		for(int i=0;i+w2<=w1;i++)		//column
		{
			cnt=0;
			for(int k=0;k<m;k++)
				for(int l=0;l<w2;l++)
					if(arr1[j+k][i+l]==arr2[k][l])
						cnt++;
			if(cnt==m*w2)
			{
				cout<<"Yes";
				return 0;
			}
		}
	cout<<"No";
	return 0;
	
}


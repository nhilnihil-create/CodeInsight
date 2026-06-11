#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n;
	int t[n];
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
	}
	cin>>m;
	int p,x;
	while(m--){
		cin>>p;
		cin>>x;
		
			int result=0;
			for(int i=1;i<=n;i++)
			{
				result=result+t[i];
			}
			cout<<result-t[p]+x<<endl;	
	}


	return 0;
}